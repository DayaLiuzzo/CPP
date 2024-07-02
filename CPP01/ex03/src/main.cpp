
#include <limits>
#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

#define HORDE_SIZE 5

int main(int ac, char **av)
{
    if(ac != 1)
    {
        std::cout << "Wrong argument count" << std::endl;
        return(1);
    }
    (void)av;
    Weapon Sword = Weapon("Sword");
    HumanA Daniel("Daniel", Sword);
    Daniel.attack();
    Sword.setType("SHIELD");
    Daniel.attack();

    Weapon DiscoStick = Weapon("Disco Stick");
    HumanB Dylan("Dylan");
    Dylan.setWeapon(DiscoStick);
    Dylan.attack();
    DiscoStick.setType("paparazzi");
    Dylan.attack();
}