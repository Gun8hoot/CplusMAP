#include <cstdlib>
#include <iostream>
#include <cstring>

// Network libs
#include <ostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


using namespace std;

// Can't scan port higher above 1017, need to allocate more memory

int scan(char *IP, int *nmbOpenPort) {
    unsigned short maxPort = 65535;
    int currentPort = 0;

    for (int currentPort; currentPort <= maxPort; currentPort++) {
        int sockFd = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(currentPort);
        server.sin_addr.s_addr = inet_addr(IP);

        int connectionStatus = connect(sockFd, (struct sockaddr*)&server, sizeof(server));

        if (connectionStatus == 0) {
            std::cout << "[!] Port open on : " << currentPort << "\x1b[00m" << std::endl;
            (*nmbOpenPort)++;
        }

        else {
            ;
        }
        close(sockFd);
    }


    if (currentPort == 0) {
        return 0;
    }

    else {
        return -1;
    }
}