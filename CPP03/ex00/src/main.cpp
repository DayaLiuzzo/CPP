#include "utils.hpp"
#include "ClapTrap.hpp"

int main()
{
    std::cout << LILAC_COLOR << "Testing ClapTrap constructors and copy operators" << RESET_COLOR << std::endl;

    ClapTrap claptrap_1;
    std::cout << claptrap_1;

    ClapTrap claptrap_2("Claptrap_2");
    std::cout << claptrap_2;

    ClapTrap claptrap_3(claptrap_2);
    std::cout << claptrap_3;

    claptrap_3 = claptrap_2;
    std::cout << claptrap_3;

    claptrap_3 = claptrap_1;
    std::cout << claptrap_3;

    std::cout << LILAC_COLOR << "Testing ClapTrap member functions" << RESET_COLOR << std::endl;

    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());

    std::cout << claptrap_1;

    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(claptrap_1.getAttackDamage());
    claptrap_1.attack("claptrap_2");

    claptrap_1.attack("claptrap_2");
    claptrap_2.takeDamage(11);

    std::cout << claptrap_2;
    claptrap_2.beRepaired(5);

    std::cout << claptrap_2;
    claptrap_2.beRepaired(6);

    std::cout << claptrap_2;
}