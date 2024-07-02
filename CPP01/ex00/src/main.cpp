
#include <limits>
#include <iostream>
#include "Zombie.hpp"

int main(int ac, char **av)
{
    if(ac != 1)
    {
        std::cout << "Wrong argument count" << std::endl;
        return(1);
    }
    (void)av;
    randomChump("StackZombie");
    Zombie* HeapZombie = newZombie("HeapZombie");
    HeapZombie->announce();
    delete HeapZombie;

    return(0);
}
