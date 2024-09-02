#ifndef UTILS_HPP
#define UTILS_HPP


#include <iostream>
#include <string>
#include <cstddef>

#if defined(_M_X64) || defined(__x86_64__) || defined(__ppc64__)
    typedef unsigned long long uintptr_t;
#else
    typedef unsigned long uintptr_t;  
#endif

#define YELLOW_COLOR "\033[38;2;236;245;66m"
#define LILAC_COLOR "\033[38;2;182;126;222m"
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[38;2;201;59;40m"
#define GREEN_COLOR "\033[38;2;50;227;79m"

void print_message(std::string msg, std::string color);

#endif // UTILS_HPP

