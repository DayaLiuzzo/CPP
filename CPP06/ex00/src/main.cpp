#include "utils.hpp"
#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        print_message("Error: Invalid number of arguments", RED_COLOR);
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}