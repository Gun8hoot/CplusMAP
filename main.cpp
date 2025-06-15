#include "./lib/main.hpp"
#include <cstdlib>

using namespace std;            // For type string & std

int main(int    argv, char  *argc[]) {
    // INIT
    int done;
    unsigned short *nmbOpenPort;
    int corrctIP;

    corrctIP = 0;
    done = 0;
    //speed = 0;     // To faster to slower

    char*   IP = (char*)malloc(sizeof(unsigned long) * 17);
    if (IP == NULL) {
        std::cout <<"\x1b[0;31m" << "[!] FAILED TO ALLOCATE MEMORY FOR THE IP" << "\x1b[0m" << std::endl; 
        return (1);
    }

    nmbOpenPort = (unsigned short*)malloc(sizeof(unsigned short) * 5);
    if (nmbOpenPort == NULL) {
        std::cout <<"\x1b[0;31m[!] FAILED TO ALLOCATE MEMORY FOR THE COUNTER\x1b[0m" << std::endl;
        free(IP);
        return (1);
    }

    *nmbOpenPort = 0;
    strcpy(IP, "");
    
    // CORE
    showBanner();
    arguments(argv, argc, &IP); // 
    corrctIP = check_ip(IP);
    if (corrctIP == 1) {
        std::cout <<"\x1b[0;31m[!] YOU HAVE ENTER AN INCORRECT IP, ONLY IPv4 IP WILL WORK\x1b[0m" << std::endl;
        free(nmbOpenPort);
        free(IP);
        return (1);
    }

    std::chrono::time_point<std::chrono::system_clock> startTime = std::chrono::system_clock::now();
    done = scan(IP, nmbOpenPort);
    std::chrono::time_point<std::chrono::system_clock> endTime = std::chrono::system_clock::now();
    std::chrono::duration<double> RAW_duration = endTime-startTime;
    double totalDuration = RAW_duration.count();


    if (done == 0) {
        std::cout << "\x1b[0;32m[+] Finish, found " << *nmbOpenPort << " port open. ";
    }

    else if (done != 0) {
        std::cout << "\x1b[0;31m[!] ERROR : FAILED TO FINISH THE SCANNING FONCTION\n\x1b[0m";
        free(IP);
        free(nmbOpenPort);
        exit(1);
        //errorMessages("NOT_FINISH_ERROR");
    }

    std::cout << "Have scan every port in "<< totalDuration << "s\x1b[00m" << std::endl;
    
    // MEMORY FREED
    if (IP) free(IP);
    if (nmbOpenPort) free(nmbOpenPort);
    return 0;
}
