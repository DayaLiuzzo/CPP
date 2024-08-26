#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat : public WrongAnimal {
private:
    // Class members go here
public:
    WrongCat(); // Default constructor
    WrongCat(const WrongCat &other); // Copy constructor
    WrongCat &operator=(const WrongCat &other); // Copy assignment operator
    ~WrongCat(); // Destructor
    void makeSound() const;
protected:
    std::string type;
};

#endif // WrongCAT_HPP

