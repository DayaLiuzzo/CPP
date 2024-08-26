#include "Dog.hpp"
#include "utils.hpp"

Dog::Dog() 
{
    this->type = "Dog";
    std::cout << GREEN_COLOR << "Dog default constructor called" << RESET_COLOR << std::endl;
}

Dog::Dog(const Dog &other) 
{
    std::cout << GREEN_COLOR << "Dog copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other) 
{
    std::cout << GREEN_COLOR << "Dog copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
        // Copy the data from 'other' to 'this'
    }
    return *this;
}
void Dog::makeSound() const
{
    std::cout << "Wouaf Wouaf Wouaf" << std::endl;
}
Dog::~Dog() 
{
    std::cout << RED_COLOR << "Dog destructor called" << RESET_COLOR << std::endl;
}

