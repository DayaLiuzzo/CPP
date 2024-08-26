#include "WrongAnimal.hpp"
#include "utils.hpp"

WrongAnimal::WrongAnimal() 
{
    std::cout << GREEN_COLOR << "WrongAnimal default constructor called" << RESET_COLOR << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) 
{
    std::cout << GREEN_COLOR << "WrongAnimal copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) 
{
    std::cout << GREEN_COLOR << "WrongAnimal copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
       this->type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
    std::cout << RED_COLOR << "WrongAnimal destructor called" << RESET_COLOR << std::endl;
}

