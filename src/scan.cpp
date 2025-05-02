#include <cstdlib>
#include <iostream>
#include <cstring>

// Network libs
#include <iterator>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

// Can't scan port higher that 1017, need to allocate more memory

int scan(char *IP) {
    unsigned short PORT = 0;
    //int count;
    int *count = (int*)malloc(sizeof(int ));
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(IP);


    for (int i = 0; i <= 65535; i++) {
        int sockFd = socket(AF_INET, SOCK_STREAM, 0);
        PORT = i;
        int connectStatus;
        servAddr.sin_port = htons(PORT);
        if(i == 5000) {
            std::cout << i << std::endl;
        }
        if ((connectStatus = connect(sockFd, (struct sockaddr*)&servAddr, sizeof(servAddr))) < 0) {
            ;
        }

        if (connectStatus == 0) {
            std::cout << "\x1b[38;5;118m[!] Port open on : " << PORT << "\x1b[00m" << std::endl;
            
        }
    }

    if (PORT == 65535) {
        free(count);
        return 1;
    }

    else {
        return -1;
    }
}