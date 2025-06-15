#include <iostream>
#include <unistd.h>
#include <chrono>
#include <cstring>

#include "./ft_banner.hpp"
#include "./ft_arguments.hpp"
#include "./ft_scan.hpp"

void showBanner(void);
void arguments(int argc, char *argv[], char **IP);
int check_ip(char *IP);
int scan(char *IP, unsigned short *nmbOpenPort);
