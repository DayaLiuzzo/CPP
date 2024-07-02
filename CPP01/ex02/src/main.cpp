
#include <limits>
#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if(ac != 1)
    {
        std::cout << "Wrong argument count" << std::endl;
        return(1);
    }
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << &string << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << string << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}