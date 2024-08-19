#include "utils.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
 std::cout << LILAC_COLOR << "Testing ScavTrap constructors and copy operators" << RESET_COLOR << std::endl;

    ScavTrap ScavTrap_1;
    std::cout << ScavTrap_1;

    ScavTrap ScavTrap_2("ScavTrap_2");
    std::cout << ScavTrap_2;

    ScavTrap ScavTrap_3(ScavTrap_2);
    std::cout << ScavTrap_3;

    ScavTrap_3 = ScavTrap_2;
    std::cout << ScavTrap_3;

    ScavTrap_3 = ScavTrap_1;
    std::cout << ScavTrap_3;

    std::cout << LILAC_COLOR << "Testing ScavTrap member functions" << RESET_COLOR << std::endl;

    std::cout << ScavTrap_1;
    ScavTrap_1.attack("ScavTrap_2");
    ScavTrap_2.takeDamage(ScavTrap_1.getAttackDamage());

    std::cout << ScavTrap_2;
    ScavTrap_2.beRepaired(100);
    std::cout << ScavTrap_2;
    ScavTrap_2.guardGate();

    ScavTrap_2 = ScavTrap_1;
    std::cout << ScavTrap_2;
}