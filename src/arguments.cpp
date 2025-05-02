#include <cstddef>
#include <iostream>
#include <cstring>
#include <ostream>
using namespace std;

void arguments(int argc, char *argv[], char **IP) {
    const char argumentAllow[4][12] = {"-i", "-I", "-h", "-H"};
    argc = argc-1;

    if (argc <= 0) {
        std::cout << "You need at least 1 arguments: ./main -i/-I {IP} -h/-H \n";
        exit(1);
    }

    for (int i = 0; i < argc; i++) {
        if ((strcmp(argv[i], argumentAllow[2]) == 0) || strcmp(argv[i], argumentAllow[3]) == 0) {
            std::cout << "Help\n";
            exit(0);
        }

        else if ((strcmp(argv[i], argumentAllow[0]) == 0) || (strcmp(argv[i], argumentAllow[1]) == 0) && (i + 1) < argc) {
            *IP = (char *)malloc(strlen(argv[i + 1]) + 1);
            if (IP == NULL) {
                std::cerr << "[!] Memory allocation failed" << '\n';
                exit(0);
            }
            if (argc > 1) {
                for (int x(0); x <= argc; x++){
                    if (((strcmp(argv[x], argumentAllow[0])) == 0) || (strcmp(argv[x], argumentAllow[1]) == 0) && (i+1 >= argc)){
                        std::cout << argv[x+1] << std::endl;
                        break;
                    }
                }
            }
            strcpy(*IP, argv[i + 1]);
        }

        
        else {
            ;
        }
        
    }

    if (IP != NULL) {
        ;
    } 
    
    else {
        std::cout << "[!] You need to enter an IP address " << '\n';
        exit(0);
    }
}