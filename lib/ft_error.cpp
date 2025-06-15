#include "./error.h"
#include <iostream>

void errorMessages(std::string msg) {
    if (msg == "BANNER_ERROR") {
        std::cout << "[&] NON-FATAL ERROR : FAILED TO OPEN THE BANNER FILE\n";
    }
    
    else if (msg == "NOT_FINISH_ERROR") {
        std::cout << "[!] ERROR : FAILED TO FINISH THE SCANNING FONCTION\n";
        exit(1);
    }

    else if (msg == "2_ARGUMENTS_ERROR") {
        std::cout << "[!] ERROR : YOU NEED AT LEAST 2 ARGUMENTS | ./main -i {IP} \n";
        exit(1);
    }

    else if (msg == "RETR_ARGUMENTS") {
        std::cout << "[!] ERROR : FAILED TO RETRIEVE THE IP ADDRESS TO THE ARGUMENTS\n";
        exit(1);
    }
}