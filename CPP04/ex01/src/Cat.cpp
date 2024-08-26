#include "Cat.hpp"
#include "utils.hpp"

Cat::Cat() : brain(new Brain())
{
    this->type = "Cat";
    std::cout << GREEN_COLOR << "Cat default constructor called" << RESET_COLOR << std::endl;
}

Cat::Cat(const Cat &other) : Animal(), brain(new Brain(*other.brain))
{
    std::cout << GREEN_COLOR << "Cat copy constructor called" << RESET_COLOR << std::endl;
}

Cat &Cat::operator=(const Cat &other) 
{
    std::cout << GREEN_COLOR << "Cat copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}
void Cat::makeSound() const
{
    std::cout << "Miaou Miaou Miaou" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << RED_COLOR << "Cat destructor called" << RESET_COLOR << std::endl;
}

std::string Cat::getBrainIdea(int index) const
{
    return brain->getIdea(index);
}

void Cat::setBrainIdea(int index, std::string idea)
{
    brain->setIdea(index, idea);
}
