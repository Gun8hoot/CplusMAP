
#include <fstream>
#include <iostream>             // Basic C++ lib
#include <bits/stdc++.h>        // For the ifstream on showBanner
#include "./src/arguments.cpp"
#include "./src/scan.cpp"
#include <string>

using namespace std;            // For type string

void showBanner(void) {
    ifstream f("banner.txt"); // Read the file who have the banner
    if (!f.is_open()) {
        ;
    }
    string s; 

    while (getline(f, s))
        std::cout << "\x1b[38;5;93m" << s << "\x1b[00m" << std::endl;
}

int main(int argv, char *argc[]) {
    char *IP = NULL;
    int res;
    showBanner();
    arguments(argv, argc, &IP);
    res = scan(IP);
    if (res == 0) {
        return 0;
    }
    else if (res != 0) {
        std::cout << "[!] Res is not equal to 0" << std::endl;
        exit(1);
    }
    
}
