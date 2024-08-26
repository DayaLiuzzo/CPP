#include "Animal.hpp"
#include "utils.hpp"

Animal::Animal() 
{
    std::cout << GREEN_COLOR << "Animal default constructor called" << RESET_COLOR << std::endl;
}

Animal::Animal(const Animal &other) 
{
    std::cout << GREEN_COLOR << "Animal copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

Animal &Animal::operator=(const Animal &other) 
{
    std::cout << GREEN_COLOR << "Animal copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
       this->type = other.type;
    }
    return *this;
}

// void Animal::makeSound() const
// {
//     std::cout << "Animal sound" << std::endl;
// }

Animal::~Animal() 
{
    std::cout << RED_COLOR << "Animal destructor called" << RESET_COLOR << std::endl;
}

