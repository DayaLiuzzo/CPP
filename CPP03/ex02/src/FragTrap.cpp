#include "FragTrap.hpp"
#include "utils.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    setName("Default FragTrap");
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
    std::cout << GREEN_COLOR << "FragTrap default constructor called" << RESET_COLOR << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << GREEN_COLOR << "FragTrap copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) 
{
    std::cout << GREEN_COLOR << "FragTrap copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) 
    {
        this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
    }
    return *this;
}

FragTrap::~FragTrap() 
{
    std::cout << RED_COLOR << "FragTrap destructor called" << RESET_COLOR << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << GREEN_COLOR << "FragTrap parameterized constructor called" << RESET_COLOR << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << YELLOW_COLOR << "FragTrap " << getName() << " requests a high five!" << RESET_COLOR << std::endl;
}
void FragTrap::attack(const std::string &target)
{
    if (getEnergyPoints() == 0)
    {
        std::cout << YELLOW_COLOR << getName() << " is out of energy points!" << RESET_COLOR << std::endl;
        return ;
    }
    if (getHitPoints() == 0)
    {
        std::cout << YELLOW_COLOR << getName() << " is dead!" << RESET_COLOR << std::endl;
        return ;
    }
    std::cout << YELLOW_COLOR << "FragTrap " << getName() << " attacks " << target << " causing " << getAttackDamage() << " points of damage!" << RESET_COLOR << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
}
void FragTrap::beRepaired(unsigned int amount)
{
    if (getEnergyPoints() == 0)
    {
        std::cout << YELLOW_COLOR << getName() << " is out of energy points!" << RESET_COLOR << std::endl;
        return ;
    }
    if (getHitPoints() == 100)
    {
        std::cout << YELLOW_COLOR << getName() << " is already at full health!" << RESET_COLOR << std::endl;
        return ;
    }
    std::cout << YELLOW_COLOR << getName() << " is being repaired for " << amount << " points!" << RESET_COLOR << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
    if (amount + getHitPoints() >= 100)
    {
        setHitPoints(100);
        std::cout << YELLOW_COLOR << getName() << " is at full health!" << RESET_COLOR << std::endl;
        return ;
    }
    setHitPoints(getHitPoints() + amount);
}