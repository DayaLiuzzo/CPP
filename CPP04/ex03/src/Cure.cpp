#include "Cure.hpp"

//constructor
Cure::Cure()
{
    _type = "cure";
   _character = NULL;
   _materiaSource = NULL;
}

Cure::Cure(const Cure &other) 
{
    _type = other._type;
   _character = other._character; 
   _materiaSource = NULL;
   
}

//operators
Cure &Cure::operator=(const Cure other) 
{
    std::cout << "That doesn't make sense" << std::endl;
    (void) other;
    return *this;
}

//member functions
void Cure::use(ICharacter &target) 
{
    std::cout << "Heals" << target.getName() << "wounds" << std::endl;
}

AMateria *Cure::clone() const 
{
    AMateria *tmp = new Cure(*this);
    tmp->setCharacter(NULL);
    tmp->setMateriaSource(NULL);
    return tmp;
}

//destructor
Cure::~Cure() {}

