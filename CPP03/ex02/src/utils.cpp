#include "utils.hpp"

void print_message(std::string msg, std::string color)
{
    std::cout << color << msg << RESET_COLOR << std::endl;
}