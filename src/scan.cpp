#include <cstdlib>
#include <iostream>
#include <cstring>

// Network libs
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

// Can't scan port higher above 1017, need to allocate more memory

int scan(char *IP) {
    unsigned short PORT = 0;
    int *count = (int*)malloc(sizeof(int ));
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    
    servAddr.sin_addr.s_addr = inet_addr(IP);
    

    for (int i = 0; i <= 65535; i++) {
        count++;
        int sockFd = socket(AF_INET, SOCK_STREAM, 0);
        PORT = i;
        int connectStatus = (unsigned long)malloc(sizeof(int));
        std::cout << sizeof(connectStatus) << std::endl;
        servAddr.sin_port = htons(PORT);
        connectStatus = connect(sockFd, (struct sockaddr*)&servAddr, sizeof(servAddr));
        if (connectStatus < 0) {
            ;
            //std::cout << "port : " << i << " res eq to " << res << std::endl;
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
        std::cout << "Failed to scan every port, some open can miss";
        return -1;
    }
}