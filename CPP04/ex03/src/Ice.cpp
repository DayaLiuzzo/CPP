#include "Ice.hpp"

// constructors
Ice::Ice()
{
	this->_type = "ice";
	this->_character = NULL;
	this->_materiaSource = NULL;
}

Ice::Ice(const Ice &other)
{
	this->_type = other._type;
	this->_character = other._character;
	this->_materiaSource = other._materiaSource;
}
// operators
Ice &Ice::operator=(const Ice other)
{
	std::cout << "That doesnt make sense... " << std::endl;
	(void)other;
    return (*this);
}

// member functions
void Ice::use(ICharacter &target)
{
	std::cout << "Shoots an ice bolt at" << target.getName() << std::endl;
}

AMateria *Ice::clone() const
{
	AMateria *tmp = new Ice(*this);
	tmp->setCharacter(NULL);
	tmp->setMateriaSource(NULL);
	return (tmp);
}

// destructors
Ice::~Ice(){}