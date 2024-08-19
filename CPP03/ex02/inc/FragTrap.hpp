#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    // Class members go here
public:
    FragTrap(); // Default constructor
    FragTrap(std::string name); // Parameterized constructor
    FragTrap(const FragTrap &other); // Copy constructor
    FragTrap &operator=(const FragTrap &other); // Copy assignment operator
    ~FragTrap(); // Destructor
    // Member functions go here
    void highFivesGuys(void);
    void attack(const std::string &target);
    void beRepaired(unsigned int amount);
    
};

#endif // FRAGTRAP_HPP

