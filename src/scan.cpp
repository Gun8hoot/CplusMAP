#include <iostream>
#include <cstring>

// Network part
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int scan(char IP) {
    unsigned short PORT = 0;
    int connectStatus;
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(IP);
    for (int i = 0; i <= 65535; i++){
        int sockFd = socket(AF_INET, SOCK_STREAM, 0);
        PORT = i;
        servAddr.sin_port = htons(PORT);
        if ((connectStatus = connect(sockFd, (struct sockaddr*)&servAddr, sizeof(servAddr))) < 0) {
            ;
        }
        if (connectStatus == 0) {
            std::cout << "[!] Port open on : " << PORT << std::endl;
        }
        close(sockFd);
    }

    return 0;
}