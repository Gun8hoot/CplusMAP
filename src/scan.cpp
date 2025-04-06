#include <iostream>
#include <cstring>

// Network libs
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int scan(char *IP) {
    unsigned short PORT = 0;
    int connectStatus;
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(IP);
    for (int i = 0; i <= 65535; i++) {
        int sockFd = socket(AF_INET, SOCK_STREAM, 0);
        PORT = i;
        servAddr.sin_port = htons(PORT);
        if ((connectStatus = connect(sockFd, (struct sockaddr*)&servAddr, sizeof(servAddr))) < 0) {
            ;
        }
        if (connectStatus == 0) {
            std::cout << "\x1b[38;5;118m[!] Port open on : " << PORT << "\x1b[00m" << std::endl;
        }
        close(sockFd);
    }
    if (PORT <= 65535) {
        return 0;
    }

    else {
        return -1;
    }
}