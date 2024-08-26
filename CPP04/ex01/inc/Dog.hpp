#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
  private:
	Brain *brain;
	// Class members go here
  public:
	Dog();                            // Default constructor
	Dog(const Dog &other);            // Copy constructor
	Dog &operator=(const Dog &other); // Copy assignment operator
	~Dog();                           // Destructor
	void makeSound() const;
	std::string getBrainIdea(int index) const;
    void setBrainIdea(int index, std::string idea);
  protected:
	std::string type;
};
#endif // DOG_HPP

