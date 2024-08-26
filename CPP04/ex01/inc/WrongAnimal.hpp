#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
private:
    // Class members go here
public:
    WrongAnimal(); // Default constructor
    WrongAnimal(const WrongAnimal &other); // Copy constructor
    WrongAnimal &operator=(const WrongAnimal &other); // Copy assignment operator
    virtual ~WrongAnimal(); // Destructor
    void makeSound() const;
    //getters and setters
    std::string getType() const { return type; }
    void setType(std::string type) { this->type = type; }
protected:
    std::string type;
};

#endif // WrongANIMAL_HPP

