
#include <limits>
#include <iostream>
#include "Zombie.hpp"

#define HORDE_SIZE 5

int main(int ac, char **av)
{
    (void)av;
    if(ac != 1)
    {
        std::cout << "Wrong argument count" << std::endl;
        return(1);
    }
    Zombie* Horde = zombieHorde(HORDE_SIZE, "Loosers");
    delete[] Horde;
    return(0);
}
void randomChump(std::string name)
{
    Zombie chump;
    chump.setName(name);
    chump.announce();
}
Zombie* newZombie(std::string name)
{
    Zombie* newZombie = new Zombie();
    newZombie->setName(name);
    return newZombie;
}