#include "WrongCat.hpp"
#include "utils.hpp"

WrongCat::WrongCat() : WrongAnimal() 
{
    this->type = "WrongCat";
    std::cout << GREEN_COLOR << "WrongCat default constructor called" << RESET_COLOR << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
    std::cout << GREEN_COLOR << "WrongCat copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) 
{
    std::cout << GREEN_COLOR << "WrongCat copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
void WrongCat::makeSound() const
{
    std::cout << "Uoaim Uoaim Uoaim" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << RED_COLOR << "WrongCat destructor called" << RESET_COLOR << std::endl;
}

