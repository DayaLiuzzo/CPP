#include "AMateria.hpp"

//constructor
AMateria::AMateria()
{
	_type = "default";
	_character = NULL;
	_materiaSource = NULL;
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
    _character = NULL;
    _materiaSource = NULL;
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	_character = NULL;
	_materiaSource = NULL;
}
//getters and setters
Character *AMateria::getCharacter() const
{
	return (this->_character);
}

std::string const &AMateria::getType() const
{
    return (_type);
}

MateriaSource *AMateria::getMateriaSource() const
{
	return (this->_materiaSource);
}

void AMateria::setCharacter(Character *character)
{
	this->_character = character;
}
void AMateria::setMateriaSource(MateriaSource *materiaSource)
{
	this->_materiaSource = materiaSource;
}

//operators
AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

//destructors
AMateria::~AMateria(){}
