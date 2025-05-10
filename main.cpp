#include "./lib/arguments.cpp"
#include "./lib/scan.cpp"
#include "./lib/banner.cpp"
#include "./lib/main.h"
#include <ratio>
#include <unistd.h>
#include <chrono>


using namespace std;            // For type string & std

/*
    The project is finshed at 60/70%

HAVE FIXED: 
 - ARGUMENT BUG
 - SCAN AND DETECTED OPEN PORT (fuxking loop) // - Cant connect after 1017 connection (veryyy far of 65535)
 - FOLDER STRUCTURE
 - nmbOpenPort IS FIXED
 - FIX THE munmap_chunk()


NEED TO DO: 
 - POLISH THE CODE (HE IS UGLY ASFK)
 - OUTPUT TO A FILE ARGMUENT LIKE -o {file.txt}
 - SOME OPTIMIZATION TO GAIN SPEED
 - CODED THE FONCTION TO CHECK IF THE GIVEN IP IS AN IPV4 AND NOT A RANDOM BUCH OF INTEGER OR CHARACTER 
 - ERROR MESSAGE FONCTION 
 - TRY SWITCH TO TCP STEALTH FOR ENHANCE STEALTH
 - SHOW WICH SERVICE IS GENERALLY ON THIS PORT https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml
 - CREATE A MAKE FILE
 - -T flag to slow the process (enhance stealth)
 - ADD COMPATIBILITY TO WINDOWS USERS

*/

int main(int argv, char *argc[]) {
    // INIT
    int done = 0;
    int timing = 0;     // To faster to slower

    char* IP = (char*)malloc(sizeof(unsigned long));
    std::cout << "size : " << IP<< std::endl;
    if (IP == NULL) {
        std::cout <<"\x1b[0;31m" << "[!] FAILED TO ALLOCATE MEMORY FOR THE IP" << "\x1b[0m" << std::endl; 
        exit(1);
    }
    else {;}

    unsigned short *nmbOpenPort = (unsigned short*)malloc(sizeof(unsigned short));
    if (nmbOpenPort == NULL) {
        std::cout <<"\x1b[0;31m[!] FAILED TO ALLOCATE MEMORY FOR THE COUNTER\x1b[0m" << std::endl;
        free(IP);
        exit(1);
    }
    else {;}

    *nmbOpenPort = 0;
    strcpy(IP, "");
    
    // CORE
    showBanner();
    arguments(argv, argc, &IP); // 
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
