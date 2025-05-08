#ifndef COLOR_H_
#define COLOR_H_

#include <string>

class colorClass {
public:
    std::string red = "\e[0;31m";
    std::string purple = "\x1b[38;5;93m";
    std::string reset = "\x1b[0m";
    std::string yellow = "\x1b[0;33m";
};

extern colorClass color;

#endif  // COLOR_H_