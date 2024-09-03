#include "iter.hpp"

int main(void)
{
    int int_array[] = {1, 2, 3, 4, 5};
    std::string string_array[] = {"Hello", "World", "!"};

    std::cout << "Fastidious, creating one function per type"<< std::endl;
    iter(int_array, 5, print_int);
    iter(string_array, 3, print_message);
    std::cout << std::endl;
    std::cout << "--------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Efficient, creating one function template to handle all types"<< std::endl;
    iter(int_array, 5, test);
    iter(string_array, 3, test);
    return 0;
}
void print_message(const std::string &msg)
{
    std::cout << msg << std::endl;
}

void print_int(const int &i)
{
    std::cout << i << std::endl;
}