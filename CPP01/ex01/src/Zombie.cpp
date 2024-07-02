#include "Zombie.hpp"


void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
    name = "Unnamed Zombie";
}
Zombie::~Zombie(){
    std::cout << name << " is destroyed." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}