#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <nlohmann/json.hpp>
#include <stdio.h>

int main(int argc, const char **argv) {
  if (argc < 2) {
    return 0;
  }
  std::string text;
  std::ifstream ifs(argv[1]);
  nlohmann::json json;
  ifs >> json;

  std::filesystem::create_directories("images/compatibility");

  std::vector<nlohmann::json> jsons = json;
  for (auto &issue : jsons) {
    std::string url = issue["html_url"];
    std::string name = issue["title"];
    std::string id = std::to_string(issue["number"].get<int>());
    auto labels = issue["labels"];
    std::string working;
    std::string image = "";
    std::string category;

    for (auto &label : labels) {
      std::string lname = label["name"];
      if (lname == "only menu" || lname == "sorta working") {
        working = "<span class=\"status yellow\">Partially Working</span>";
        category = "partial";
        break;
      } else if (lname == "not working") {
        working = "<span class=\"status red\">Not Working</span>";
        category = "not-working";
        break;
      } else if (lname == "working") {
        working = "<span class=\"status green\">Working</span>";
        category = "working";
        break;
      }
    }
    if (category.empty()) {
      category = "untested";
      working = "<span class=\"status gray\">Untested</span>";
    }

    std::string body =
        issue["body"].is_null() ? "" : issue["body"].get<std::string>();
    std::string image_prefix = "https://github.com/user-attachments/assets/";
    size_t x = body.find(image_prefix);

    if (x == std::string::npos) {
      image = "{{ site.baseurl }}/images/felix86NoThoughts.png";
    } else {
      std::string source_url = body.substr(x, image_prefix.length() + 36);
      std::string path = "images/compatibility/" + id + ".jpg";
      std::string local_path = "../" + path;
      std::string web_path = "{{ site.baseurl }}/" + path;
      if (!std::filesystem::exists(local_path)) {
        std::string tmp_path = local_path + ".tmp";
        std::string curl_cmd =
            "curl -sL \"" + source_url + "\" -o \"" + tmp_path + "\"";
        std::string convert_cmd = "convert \"" + tmp_path +
                                  "\" -resize 320x180^ -gravity center -extent "
                                  "320x180 -quality 80 \"" +
                                  local_path + "\"";
        std::string cleanup_cmd = "rm \"" + tmp_path + "\"";

        if (std::system(curl_cmd.c_str()) == 0) {
          std::system(convert_cmd.c_str());
          std::system(cleanup_cmd.c_str());
        }
      }

      image = std::filesystem::exists(local_path) ? web_path : source_url;
    }

    printf("<div class=\"game-card\" data-category=\"%s\">\n",
           category.c_str());
    printf("  <div class=\"game-image-container\">\n");
    printf("    <img loading=\"lazy\" src=\"%s\" alt=\"%s\" "
           "class=\"game-image\">\n",
           image.c_str(), name.c_str());
    printf("  </div>\n");
    printf("  <div class=\"game-info\">\n");
    printf("    <h3 class=\"game-title\"><a href=\"%s\">%s</a></h3>\n",
           url.c_str(), name.c_str());
    printf("    %s\n", working.c_str());
    printf("  </div>\n");
    printf("</div>\n");
  }
}