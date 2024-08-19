#include "ScavTrap.hpp"
#include "utils.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	setName("Default ScavTrap");
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << GREEN_COLOR << "ScavTrap default constructor called" << RESET_COLOR << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << GREEN_COLOR << "ScavTrap copy constructor called" << RESET_COLOR << std::endl;
	*this = other;
}
void ScavTrap::guardGate()
{
	if(this->getHitPoints() == 0)
	{
		std::cout << YELLOW_COLOR << "ScavTrap " << this->getName() << " is dead!" << RESET_COLOR << std::endl;
		return ;
	}
	std::cout << YELLOW_COLOR << "ScavTrap " << this->getName() << " has entered in Gate keeper mode" << RESET_COLOR << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << GREEN_COLOR << "ScavTrap parameterized constructor called" << RESET_COLOR << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << GREEN_COLOR << "ScavTrap copy assignment operator called" << RESET_COLOR << std::endl;
	if (this != &other)
	{
		this->setName(other.getName());
		this->setHitPoints(other.getHitPoints());
		this->setEnergyPoints(other.getEnergyPoints());
		this->setAttackDamage(other.getAttackDamage());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << RED_COLOR << "ScavTrap destructor called" << RESET_COLOR << std::endl;
}
void ScavTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << YELLOW_COLOR << this->getName() << " is out of energy points!" << RESET_COLOR << std::endl;
		return ;
	}
	if (this->getHitPoints() == 100)
	{
		std::cout << YELLOW_COLOR  << this->getName() << " is already at full health!" << RESET_COLOR << std::endl;
		return ;
	}
	std::cout << YELLOW_COLOR  << this->getName() << " is being repaired for " << amount << " points!" << RESET_COLOR << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	if (amount + this->getHitPoints() > 100)
	{
		this->setHitPoints(100);
		std::cout << YELLOW_COLOR  << this->getName() << " is at full health!" << RESET_COLOR << std::endl;
		return ;
	}
	this->setHitPoints(this->getHitPoints() + amount);
}
void ScavTrap::attack(const std::string &target)
{
	if (this->getEnergyPoints() == 0)
	{
		std::cout << YELLOW_COLOR << "ScavTrap " << this->getName() << " is out of energy points!" << RESET_COLOR << std::endl;
		return ;
	}
	if (this->getHitPoints() == 0)
	{
		std::cout << YELLOW_COLOR << "ScavTrap " << this->getName() << " is dead!" << RESET_COLOR << std::endl;
		return ;
	}
	std::cout << YELLOW_COLOR << "ScavTrap " << this->getName() << " attacks " << target << ",causing " << this->getAttackDamage() << " points of damage!" << RESET_COLOR << std::endl;
	this->setEnergyPoints(this->getEnergyPoints() -1);
}