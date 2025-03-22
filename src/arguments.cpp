#include <cstddef>
#include <iostream>
#include <cstring>
#include <ostream>

/* TODO : 
*   - The IP is not print on the main function 
*   
*
*/

void arguments(int argc, char *argv[], char (*IP)) {

    for (int i = 0; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0 && (i + 1) < argc) {
            IP = (char *)malloc(strlen(argv[i + 1]) + 1);
            if (IP == NULL) {
                std::cerr << "Memory allocation failed" << std::endl;
                exit(0);
            }
            strcpy(IP, argv[i + 1]);
            break; 
        }
    }

    if (IP != NULL) {
        ;
    } 
    
    else {
        std::cout << "[!] You need to enter an IP address " << std::endl;
        exit(0);
    }
}