
// lib
#include <fstream>  
#include <iostream>             // Basic C++ lib
#include <bits/stdc++.h>        // For the ifstream on showBanner
#include <string>

#include "./lib/arguments.cpp"
#include "./lib/scan.cpp"


using namespace std;            // For type string & std


/*
    The project is finshed at 60/70%

HAVE FIXED: 
 - ARGUMENT BUG
 - SCAN AND DETECTED OPEN PORT (fuxking loop) // - Cant connect after 1017 connection (veryyy far of 65535)
 - FOLDER STRUCTURE
 - nmbOpenPort IS FIXED


NEED TO DO: 
 - POLISH THE CODE (HE IS UGLY ASFK)
 - MORE COLORS
 - OUTPUT TO A FILE ARGMUENT LIKE -o {file.txt}
 - TIMER
 - SOME OPTIMIZATION TO GAIN SPEED
 - CODED THE FONCTION TO CHECK IF THE GIVEN IP IS AN IPV4 AND NOT A RANDOM BUCH OF INTEGER OR CHARACTER 
 - COLOR IS CURRENTLY NOT WORKING TOO, I WILL PROBABLY NEED TO FLUSH OLD CONTENT OR CHANGE THE COLOR SYSTEM TO DISPLAY ON THE TERM (NEED TO SWITCH FROM A FUNCTION TO AN OBJECT)
 - ERROR MESSAGE FONCTION 
 - TRY SWITCH TO TCP STEALTH TO ENHANCE STEALTH 

*/

void showBanner(void) {
    std::string line; 

    ifstream file("./src/banner.txt"); // Read the banner file
    if (!file.is_open()) {
        std::cout << "[&] NON-FATAL ERROR : FAILED TO OPEN THE BANNER FILE\n";
    }

    while (getline(file, line))
        std::cout /*color("purple")*/ << line << /*color("reset")*/ std::endl;
}


int main(int argv, char *argc[]) {
    // 4 BYTES MEMORY ALLOCATION FOR IP ADDRESS
    char* IP = (char*)malloc(sizeof(unsigned long));
    if (IP == NULL) {
        std::cout <<"[!] FAILED TO ALLOCATE MEMORY FOR THE IP" << std::endl;
        exit(1);
    }
    else {;}

    
    int *nmbOpenPort = (int*)malloc(sizeof(unsigned short));
    if (IP == NULL) {
        std::cout << "[!] FAILED TO ALLOCATE MEMORY FOR THE COUNTER" << std::endl;
        exit(1);
    }
    else {;}

    int done {0};

    showBanner();
    arguments(argv, argc, &IP); // 
    done = scan(IP, nmbOpenPort);

    if (done == 0) {
        std::cout << "[+] Finish, found " << *nmbOpenPort << " port open." << std::endl;
        return 0;
    }

    else if (done != 0) {
        std::cout << "[!] ERROR : FAILED TO FINISH THE SCANNING FONCTION\n"; exit(1);
        //errorMessages("NOT_FINISH_ERROR");
    }

    // MEMORY FREED
    free(IP);
    free(nmbOpenPort);
    return 0;
}
