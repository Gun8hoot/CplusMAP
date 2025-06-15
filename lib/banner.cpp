#include "./banner.hpp"

using namespace std;

void showBanner(void) {
    std::string line; 

    ifstream file("./src/banner.txt"); // Read the banner file
    if (!file.is_open()) {
        std::cout << "\x1b[0;31m" <<  "[&] NON-FATAL ERROR : FAILED TO OPEN THE BANNER FILE\n" << "\x1b[0m";
    }

    while (getline(file, line))
        std::cout /*color("purple")*/ << "\x1b[38;5;93m" <<  line << "\x1b[0m" <<  std::endl;
}