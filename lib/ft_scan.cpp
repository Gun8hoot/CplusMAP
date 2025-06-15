#include "./ft_scan.hpp"

int scan(char *IP, unsigned short *nmbOpenPort) {
    unsigned short maxPort = 65535;
    int currentPort;
    currentPort = 1;

    while (currentPort <= maxPort) {
        int sockFd = socket(AF_INET, SOCK_STREAM, 0);
        sockaddr_in server;
        server.sin_family = AF_INET;
        server.sin_port = htons(currentPort);
        server.sin_addr.s_addr = inet_addr(IP);

        int connectionStatus = connect(sockFd, (struct sockaddr*)&server, sizeof(server));

        if (connectionStatus == 0) {
            std::cout << "\x1b[0;33m[!] Port open on : " << currentPort << "\x1b[00m" << std::endl;
            (*nmbOpenPort)++;
        }
        close(sockFd);
        currentPort++;
    }

    if (currentPort == maxPort+1) {
        return 0;
    }

    else {
        return -1;
    }
}