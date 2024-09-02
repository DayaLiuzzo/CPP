#include "Base.hpp"
#include "utils.hpp"

int main()
{
    Base *base = generate();

    std::cout << "Identify base pointer: ";
    identify(base);


    std::cout << "-------------------------------" << std::endl;

    std::cout << "Identify base reference: ";
    identify(*base);


    delete base;


}