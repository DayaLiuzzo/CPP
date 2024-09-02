#include "Base.hpp"
#include "utils.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base::~Base() {}
void identifyHelper(A&) {
    std::cout << "A" << std::endl;
}

void identifyHelper(B&) {
    std::cout << "B" << std::endl;
}

void identifyHelper(C&) {
    std::cout << "C" << std::endl;
}

Base *generate(void)
{
    std::srand(std::time(0));
    
    int randNum = std::rand() % 3;
    
    if (randNum == 0)
    {
        std::cout << "generated A" << std::endl;
        return new A();
    }
    else if (randNum == 1)
    {
        std::cout << "generated B" << std::endl;
        return new B();
    }
    else
    {
        std::cout << "generated C" << std::endl;
        return new C();
    }
}
//dynamic cast return null ptr if failure
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}
//dynamic cast throw exception if failure (cant return null refferences hence the try throw catch)
void identify(Base &p)
{
    try {
        identifyHelper(dynamic_cast<A&>(p));
    } catch (...) {
        try {
            identifyHelper(dynamic_cast<B&>(p));
        } catch (...) {
            try {
                identifyHelper(dynamic_cast<C&>(p));
            } catch (...) {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}