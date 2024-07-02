#include "Harl.hpp"

Harl::Harl()
{
;
}
Harl::~Harl()
{
;
}
void Harl::complain(std::string level)
{
    void (Harl::*functions[])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    const char* functionName[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
    int i = 0;
    while(i < 4)
    {
        if(functionName[i] == level)
        {   
            (this->*(functions[i]))();
            return;
        }
        i++;

    }
}
void Harl::debug()
{
    std::cout << "DEBUG : Debug error" << std::endl;
}

void Harl::info()
{
    std::cout << "INFO : Info error" << std::endl;
}

void Harl::warning()
{
    std::cout << "WARNING : Warning error" << std::endl;
}
void Harl::error()
{
    std::cout << "ERROR : Error" << std::endl;
}
