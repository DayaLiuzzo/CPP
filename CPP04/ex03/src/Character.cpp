#include "Character.hpp"

AMateria *Character::_floor[4] = {NULL};
//constructor
Character::Character() : _name("default") 
{
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
} 

Character::Character(std::string name) : _name(name) 
{
    for(int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const Character &other) 
{
    *this = other;
}

// Member functions
std::string const &Character::getName() const 
{
    return _name;
}

void Character::equip(AMateria *m) 
{
    int i = 0;
    if(!m)
    {
        std::cout << "Materia is NULL" << std::endl;
        return;
    }
    if(m->getCharacter())
    {
        std::cout << "Materia already equipped" << std::endl;
        return;
    }
    if(m->getMateriaSource())
    {
        std::cout << "Materia already equipped to a materia source" << std::endl;
        return;
    }

    while(i < 4)
    {
        if(_inventory[i] == NULL)
        {
            _inventory[i] = m;
            m->setCharacter(this);
            std::cout << this->getName() << " equipped " << m->getType() << ". (slot "
                << i << ")" << std::endl;
            return;
        }
        i++;
    }
    std::cout << "Inventory is full, materia explodes, careful with these things...." << std::endl;
    delete m;
}

void Character::unequip(int idx) 
{
    if(idx < 0 || idx > 3)
        return;
    if(_inventory[idx] == NULL)
    {
        std::cout << "Slot is empty, cannot unequip" << std::endl;
        return;
    }
    std::cout << this->getName() << " unequipped " << _inventory[idx]->getType() << ". (slot "
        << idx << ")" << std::endl;
    // _inventory[idx]->setCharacter(NULL);
    
    int i;
    for(i = 0; i < 4; i++)
    {
        if(_floor[i] == NULL)
        {
            _floor[i] = this->_inventory[idx];
            _floor[i]->setCharacter(NULL);
            std::cout << "Materia " << _floor[i]->getType() << " is on the floor" << std::endl;
            break;
        }
    }
    if(i == 4)
    {
        std::cout << "Floor is full, you can't unequip more materias" << std::endl;
        return;    
    }
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) 
{
    if(idx < 0 || idx > 3)
        return;
    if(_inventory[idx] != NULL)
    {
        _inventory[idx]->use(target);
        delete _inventory[idx];
        _inventory[idx] = NULL;
    }
    else 
        std::cout << "Slot is empty, cannot use" << std::endl;
}

void Character::swap(Character &first, Character &second) {
  std::swap(first._name, second._name);
  std::swap(first._inventory, second._inventory);
}

Character &Character::operator=(const Character &other) 
{
    Character tmp = Character(other);
    Character::swap(*this, tmp);
    return *this;
}

Character::~Character() 
{
    for(int i = 0; i < 4; i++)
    {
        if(_inventory[i])
            delete _inventory[i];
    }
    for(int i = 0; i < 4; i++)
    {
        if(_floor[i])
        {
            delete _floor[i];
            _floor[i] = NULL;
        }   
    }    
}

