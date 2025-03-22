#include <iostream>
#include <cstring>
#include <ostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>



int main(int argv, char *argc[]) {
    int connectStatus;
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");


    for (int i = 8000; i <= 9000; i++){
        int sockFd = socket(AF_INET, SOCK_STREAM, 0);
        unsigned short PORT = i;
        servAddr.sin_port = htons(PORT);
        if ((connectStatus = connect(sockFd, (struct sockaddr*)&servAddr, sizeof(servAddr))) < 0) {
            ;
        }
        if (connectStatus == 0) {
            std::cout << "[!] Port open on : " << PORT << std::endl;
        }
        close(sockFd);
    }
    return 0; // finaly work 
}