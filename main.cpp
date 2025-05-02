
#include <algorithm>
#include <cstddef>
#include <fstream>  
#include <iostream>             // Basic C++ lib
#include <bits/stdc++.h>        // For the ifstream on showBanner
#include <string>

#include "./src/arguments.cpp"
#include "./src/scan.cpp"

using namespace std;            // For type string & std

void showBanner(void) {
    string s; 
    ifstream f("banner.txt"); // Read the file who have the banner
    if (!f.is_open()) {
        std::cout << "WARNING: during opening the banner file \n";
    }

    while (getline(f, s))
        std::cout << "\x1b[38;5;93m" << s << "\x1b[00m\n";
}

int main(int argv, char *argc[]) {
    char *IP = NULL;
    int done {0};
    showBanner();
    //arguments(argv, argc, &IP);
    IP = argc[2];
    done = scan(IP);
    if (done == 1) {
        std::cout << "[+] Finish\n";
        return 0;
    }
    else if (done != 0) {
        std::cerr << "[!] ERROR : The scanning fonction have not finish" << std::endl;
        exit(1);
    }
    
}
