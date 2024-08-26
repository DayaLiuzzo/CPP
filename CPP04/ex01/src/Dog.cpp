#include "Dog.hpp"
#include "utils.hpp"

Dog::Dog() : brain(new Brain())
{
    this->type = "Dog";
    std::cout << GREEN_COLOR << "Dog default constructor called" << RESET_COLOR << std::endl;
}

Dog::Dog(const Dog &other) : Animal(), brain(new Brain(*other.brain))
{
    std::cout << GREEN_COLOR << "Dog copy constructor called" << RESET_COLOR << std::endl;
}

Dog &Dog::operator=(const Dog &other) 
{
    std::cout << GREEN_COLOR << "Dog copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    return *this;
}
void Dog::makeSound() const
{
    std::cout << "Wouaf Wouaf Wouaf" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << RED_COLOR << "Dog destructor called" << RESET_COLOR << std::endl;
}

std::string Dog::getBrainIdea(int index) const
{
    return brain->getIdea(index);
}

void Dog::setBrainIdea(int index, std::string idea)
{
    brain->setIdea(index, idea);
}