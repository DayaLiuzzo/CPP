#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
    Animal(); // Default constructor
    Animal(const Animal &other); // Copy constructor
    Animal &operator=(const Animal &other); // Copy assignment operator
    virtual ~Animal(); // Destructor
    virtual void makeSound() const;
    //getters and setters
    std::string getType() const { return type; }
    void setType(std::string type) { this->type = type; }
protected:
    std::string type;
};

#endif // ANIMAL_HPP

