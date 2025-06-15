#include <iostream>
#include <unistd.h>
#include <chrono>
#include <cstring>

#include "./banner.hpp"
#include "./arguments.hpp"
#include "./scan.hpp"

void showBanner(void);
void arguments(int argc, char *argv[], char **IP);
int check_ip(char *IP);
int scan(char *IP, unsigned short *nmbOpenPort);
