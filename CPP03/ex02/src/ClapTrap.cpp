#include "ClapTrap.hpp"
#include "utils.hpp"

ClapTrap::ClapTrap() : Name("Default"), Hit_points(10), Energy_points(10),
	Attack_damage(0)
{
	std::cout << GREEN_COLOR << "ClapTrap default constructor called" << RESET_COLOR << std::endl;
}
ClapTrap::ClapTrap(std::string name) : Name(name), Hit_points(10),
	Energy_points(10), Attack_damage(0)
{
	std::cout << GREEN_COLOR << "ClapTrap parameterized constructor called" << RESET_COLOR << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name),
	Hit_points(other.Hit_points), Energy_points(other.Energy_points),
	Attack_damage(other.Attack_damage)
{
	std::cout << GREEN_COLOR << "ClapTrap copy constructor called" << RESET_COLOR << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << GREEN_COLOR << "ClapTrap copy assignment operator called" << RESET_COLOR << std::endl;
	if (this != &other)
	{
		this->Name = other.Name;
		this->Hit_points = other.Hit_points;
		this->Energy_points = other.Energy_points;
		this->Attack_damage = other.Attack_damage;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << RED_COLOR << "ClapTrap destructor called" << RESET_COLOR << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->Energy_points == 0)
	{
		std::cout << YELLOW_COLOR << "ClapTrap " << this->Name << " is out of energy points!" << RESET_COLOR << std::endl;
		return ;
	}
	if (this->Hit_points == 0)
	{
		std::cout << YELLOW_COLOR << "ClapTrap " << this->Name << " is dead!" << RESET_COLOR << std::endl;
		return ;
	}
	std::cout << YELLOW_COLOR << "ClapTrap " << this->Name << " attacks " << target << ",causing " << this->Attack_damage << " points of damage!" << RESET_COLOR << std::endl;
	this->Energy_points -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->Hit_points == 0)
	{
		std::cout << YELLOW_COLOR << this->Name << " is already dead!" << RESET_COLOR << std::endl;
		return ;
	}
	std::cout << YELLOW_COLOR << this->Name << " takes " << amount << " points of damage!" << RESET_COLOR << std::endl;
	if (amount > this->Hit_points)
	{
		this->Hit_points = 0;
		std::cout << YELLOW_COLOR  << this->Name << " is dead!" << RESET_COLOR << std::endl;
		return ;
	}
	this->Hit_points -= amount;
	if (this->Hit_points <= 0)
	{
		std::cout << YELLOW_COLOR  << this->Name << " is dead!" << RESET_COLOR << std::endl;
		return ;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Energy_points == 0)
	{
		std::cout << YELLOW_COLOR << this->Name << " is out of energy points!" << RESET_COLOR << std::endl;
		return ;
	}
	if (this->Hit_points == 10)
	{
		std::cout << YELLOW_COLOR  << this->Name << " is already at full health!" << RESET_COLOR << std::endl;
		return ;
	}
	std::cout << YELLOW_COLOR  << this->Name << " is being repaired for " << amount << " points!" << RESET_COLOR << std::endl;
	this->Energy_points -= 1;
	if (amount + this->Hit_points >= 10)
	{
		this->Hit_points = 10;
		std::cout << YELLOW_COLOR  << this->Name << " is at full health!" << RESET_COLOR << std::endl;
		return ;
	}
	this->Hit_points += amount;
}
std::string ClapTrap::getName() const
{
	return (Name);
}

unsigned int ClapTrap::getHitPoints() const
{
	return (Hit_points);
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return (Energy_points);
}

unsigned int ClapTrap::getAttackDamage() const
{
	return (Attack_damage);
}
void ClapTrap::setName(const std::string &name)
{
	Name = name;
}
void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	Hit_points = hitPoints;
}
void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	Energy_points = energyPoints;
}
void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	Attack_damage = attackDamage;
}

std::ostream &operator<<(std::ostream &os, const ClapTrap &claptrap)
{
	os << "Name: " << claptrap.getName() << std::endl;
	os << "Hit points: " << claptrap.getHitPoints() << std::endl;
	os << "Energy points: " << claptrap.getEnergyPoints() << std::endl;
	os << "Attack damage: " << claptrap.getAttackDamage() << std::endl;
	return (os);
}
