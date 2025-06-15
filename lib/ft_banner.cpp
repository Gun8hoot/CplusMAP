#include "./ft_banner.hpp"

void showBanner(void) {
    string line; 

    ifstream file("./src/banner.txt"); // Read the banner file
    if (!file.is_open()) {
        cout << "\x1b[0;31m[&] NON-FATAL ERROR : FAILED TO OPEN THE BANNER FILE\x1b[0m\n";
    }

    while (getline(file, line))
        cout << "\x1b[38;5;93m" <<  line << "\x1b[0m\n";
}