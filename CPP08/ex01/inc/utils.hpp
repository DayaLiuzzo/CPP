#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

#define YELLOW_COLOR "\033[38;2;236;245;66m"
#define LILAC_COLOR "\033[38;2;182;126;222m"
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[38;2;201;59;40m"
#define GREEN_COLOR "\033[38;2;50;227;79m"

void print_message(std::string msg, std::string color);
int getRandomNumber(int min, int max);
#endif // UTILS_HPP

