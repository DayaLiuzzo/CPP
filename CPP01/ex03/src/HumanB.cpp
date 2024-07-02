#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}
HumanB::~HumanB()
{
    ;
}
void HumanB::attack()
{
    if (weapon != nullptr)
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
    else{
        std::cout << this->name << " Slaps you in the fckin face betch!" << std::endl;
    }
}

void HumanB::setWeapon(Weapon &new_weapon)
{
    this->weapon = &new_weapon;
}