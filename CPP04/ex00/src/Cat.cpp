#include "Cat.hpp"
#include "utils.hpp"

Cat::Cat() : Animal() 
{
    this->type = "Cat";
    std::cout << GREEN_COLOR << "Cat default constructor called" << RESET_COLOR << std::endl;
}

Cat::Cat(const Cat &other) : Animal()
{
    std::cout << GREEN_COLOR << "Cat copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other) 
{
    std::cout << GREEN_COLOR << "Cat copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
        this->type = other.type;
    }
    return *this;
}
void Cat::makeSound() const
{
    std::cout << "Miaou Miaou Miaou" << std::endl;
}

Cat::~Cat()
{
    std::cout << RED_COLOR << "Cat destructor called" << RESET_COLOR << std::endl;
}

