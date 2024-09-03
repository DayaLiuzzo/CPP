#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

#define YELLOW_COLOR "\033[38;2;236;245;66m"
#define LILAC_COLOR "\033[38;2;182;126;222m"
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[38;2;201;59;40m"
#define GREEN_COLOR "\033[38;2;50;227;79m"

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}


void print_message(std::string msg, std::string color);

#endif // UTILS_HPP

