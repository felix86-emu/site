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
  //   printf("%s\n", json.dump().c_str());

  std::vector<nlohmann::json> jsons = json;
  for (auto &issue : jsons) {
    std::string url = issue["html_url"];
    std::string name = issue["title"];
    auto labels = issue["labels"];
    std::string working;
    std::string image = "";
    std::string category;
    // Category mapping
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

    std::string body = issue["body"].is_null() ? "" : issue["body"].get<std::string>();
    std::string image_prefix = "https://github.com/user-attachments/assets/";
    size_t x = body.find(image_prefix);
    if (x == std::string::npos) {
      image = "{{ site.baseurl }}/images/felixNoThoughts.png";
    } else {
      // Find the end of the GUID (36 chars)
      image = body.substr(x, image_prefix.length() + 36);
    }

    printf("<div class=\"game-card\" data-category=\"%s\">\n", category.c_str());
    printf("  <div class=\"game-image-container\">\n");
    printf("    <img loading=\"lazy\" src=\"%s\" alt=\"%s\" class=\"game-image\">\n",
           image.c_str(), name.c_str());
    printf("  </div>\n");
    printf("  <div class=\"game-info\">\n");
    printf("    <h3 class=\"game-title\"><a href=\"%s\">%s</a></h3>\n", url.c_str(), name.c_str());
    printf("    %s\n", working.c_str());
    printf("  </div>\n");
    printf("</div>\n");
  }
}