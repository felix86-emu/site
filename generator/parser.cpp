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
    for (auto &label : labels) {
      std::string lname = label["name"];
      if (lname == "only menu" || lname == "sorta working") {
        working = "<p class=\"status yellow\">Partially Working</p>";
        category = "partial";
        break;
      } else if (lname == "not working") {
        working = "<p class=\"status red\">Not Working</p>";
        category = "not-working";
        break;
      } else if (lname == "working") {
        working = "<p class=\"status green\">Working</p>";
        category = "working";
        break;
      }
    }

    // length after url is 36 ie: ce5c5813-977f-4f43-1111-11171944800d
    int k = sizeof("https://github.com/user-attachments/assets/") + 36 - 1;
    std::string body = issue["body"];
    int x = body.find("https://github.com/user-attachments/assets/");
    if (x == std::string::npos) {
      image = "{{ site.baseurl }}/images/felixNoThoughts.png";
    } else {
      image = body.substr(x, k);
      //   printf("image: %s\n", image.c_str());
    }

    // <div class = "game" data - category = "working">
    //     <img src="game1.jpg" alt="Game 1" width="100%">
    //     <p>Name: Game 1</p>
    //     <p class="status green">Working</p>
    // </div>

    printf("<div class=\"game\" data-category=\"%s\">", category.c_str());
    printf("<img loading=\"lazy\" src=\"%s\" alt=\"%s\" width=\"100%%\">",
           image.c_str(), name.c_str());
    printf("<p><a href=\"%s\">%s</a></p>", url.c_str(), name.c_str());
    printf("%s", working.c_str());
    printf("</div>\n");
  }
}