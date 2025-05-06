#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ostream>
using namespace std;

int isIP(char **IP){
    for (int character = 0; character <= strlen(*IP); character++){
        std::cout << *IP[character] << std::endl;
    }
    return 0;
}

void arguments(int argc, char *argv[], char **IP) {
    const char argumentAllow[4][12] = {"-i", "-I", "-h", "-H"};
    bool getIP{false};

    if (argc <= 1) {
        std::cout << "[!] You need at least 1 argument\n";
        exit(-1);
    }
    
    else {
        for (int i = 0; i <= argc; i++) {
            if ((strcmp(argv[i], argumentAllow[0])) == 0 ) {
                *IP = (char*)malloc(strlen(argv[i+1]) +1);
                if (IP == NULL) {
                    std::cerr << "Memory allocation failed";
                    exit(-1);
                }
                strcpy(*IP, argv[i+1]);
                getIP = true;
                isIP(IP);
                break;
            }

            else {
                ;
            }
        }

        if (getIP != true) {
            std::cout << "[!] Failed to retrieve the IP from the arguments\n";
            exit(-1);
        }
    }
}