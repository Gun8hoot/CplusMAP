
#include <fstream>
#include <iostream>             // Basic C++ lib
#include <bits/stdc++.h>        // For the ifstream on showBanner
#include "./src/arguments.cpp"
#include <string>

using namespace std;            // For type string

void showBanner(void) {
    ifstream f("banner.txt"); // Read the file who have the banner
    if (!f.is_open()) {
        ;
    }
    string s; 

    while (getline(f, s))
        std::cout << "\x1b[38;5;93m" << s << "\x1b[00m" << endl;

}

int main(int argv, char *argc[]) {
    char *IP = NULL;
    showBanner();
    arguments(argv, argc, IP);
    std::cout << "AUIYZGFEE : " << IP << std::endl;
    return 0;
}
