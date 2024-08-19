#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
private:
    std::string Name;
    unsigned int Hit_points;
    unsigned int Energy_points;
    unsigned int Attack_damage;
public:
    ClapTrap(); // Default constructor
    ClapTrap(std::string name); // Parameterized constructor
    ClapTrap(const ClapTrap &other); // Copy constructor
    ClapTrap &operator=(const ClapTrap &other); // Copy assignment operator
     ~ClapTrap(); // Destructor
    //member functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    // Getter functions
    std::string getName() const;
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
    // Setter functions
    void setName(const std::string& name);
    void setHitPoints(unsigned int hitPoints);
    void setEnergyPoints(unsigned int energyPoints);
    void setAttackDamage(unsigned int attackDamage);
};
    std::ostream& operator<<(std::ostream &os, const ClapTrap &claptrap); // Overload << operator

#endif // CLAPTRAP_HPP

