#include "./arguments.hpp"

/*int isIP(char **IP){
    for (int character = 0; character <= std::strlen(*IP); character++){
        std::cout << *IP[character] << std::endl;
    }
    return 0;
}*/

void arguments(int argc, char *argv[], char **IP) {
    vector<string> argumentAllow = {"-i", "-I", "-h", "-H"};      // Arguments allow

    bool getIP = false;

    if (argc <= 2) {
        cout << "\x1b[0;31m[!] ERROR : YOU NEED AT LEAST 2 ARGUMENTS | ./main -i {IP} \x1b[0m \n";
        exit(1);
        //errorMessages("2_ARGUMENTS_ERROR");
    }
    
    else {
        for (int x = 0; x < argc; x++) {
            std::string arg = argv[x];
            for (int allow = 0; allow <= 3; allow++) {
                if (argumentAllow[allow] == arg) {
                    getIP = true;
                    strcpy(*IP, argv[x+1]);
                    break;
                }
            }
        }

        if (getIP != true) {
            cout << "\x1b[0;31m[!] ERROR : YOU NEED AT LEAST 2 ARGUMENTS | ./main -i {IP} \x1b[0m \n"; exit(1);
            //errorMessages("RETR_ARGUMENTS");
        }

        else {
            ;
        }
    }
}