#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    // Class members go here
public:
    ScavTrap(); // Default constructor
    ScavTrap(std::string name); // Parameterized constructor
    ScavTrap(const ScavTrap &other); // Copy constructor
    ScavTrap &operator=(const ScavTrap &other); // Copy assignment operator
    ~ScavTrap(); // Destructor
    // Member functions go here
    void guardGate();
    void attack(const std::string &target);
    void beRepaired(unsigned int amount);
};

#endif // SCAVTRAP_HPP

