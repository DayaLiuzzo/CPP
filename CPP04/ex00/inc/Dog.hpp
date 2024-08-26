#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
public:
    Dog(); // Default constructor
    Dog(const Dog &other); // Copy constructor
    Dog &operator=(const Dog &other); // Copy assignment operator
    ~Dog(); // Destructor
    void makeSound() const;
protected:
    std::string type;
};

#endif // DOG_HPP

