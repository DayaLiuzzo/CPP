#include "Brain.hpp"
#include "utils.hpp"

Brain::Brain() 
{
    std::cout << GREEN_COLOR << "Brain default constructor called" << RESET_COLOR << std::endl;
}

Brain::Brain(const Brain &other) 
{
    std::cout << GREEN_COLOR << "Brain copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other) 
{
    int i = 0;
    std::cout << GREEN_COLOR << "Brain copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
       while (i < 100) {
           this->ideas[i] = other.ideas[i];
           i++;
       }
    }
    return *this;
}

Brain::~Brain() 
{
    std::cout << RED_COLOR << "Brain destructor called" << RESET_COLOR << std::endl;
}


std::string Brain::getIdea(int index) const
{
    if(index < 0 || index >= 100)
        return "Incorrect Index";
    return ideas[index];
}

void Brain::setIdea(int index, std::string& idea)
{
    if(index < 0 || index >= 100)
        return;
   ideas[index] = idea;
}