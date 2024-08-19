#include "utils.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
 std::cout << LILAC_COLOR << "Testing FragTrap constructors and copy operators" << RESET_COLOR << std::endl;

    FragTrap FragTrap_1;
    std::cout << FragTrap_1;

    FragTrap FragTrap_2("FragTrap_2");
    std::cout << FragTrap_2;

    FragTrap FragTrap_3(FragTrap_2);
    std::cout << FragTrap_3;

    FragTrap_3 = FragTrap_2;
    std::cout << FragTrap_3;

    FragTrap_3 = FragTrap_1;
    std::cout << FragTrap_3;

    std::cout << LILAC_COLOR << "Testing FragTrap member functions" << RESET_COLOR << std::endl;

    std::cout << FragTrap_1;
    FragTrap_1.attack("FragTrap_2");
    FragTrap_2.takeDamage(FragTrap_1.getAttackDamage());

    std::cout << FragTrap_2;
    FragTrap_2.beRepaired(100);
    std::cout << FragTrap_2;
    FragTrap_2.highFivesGuys();
    FragTrap_2.attack("FragTrap_1");
    FragTrap_1.takeDamage(FragTrap_2.getAttackDamage());
    FragTrap_2.attack("FragTrap_1");
    FragTrap_1.takeDamage(FragTrap_2.getAttackDamage());
    FragTrap_2.attack("FragTrap_1");
    FragTrap_1.takeDamage(FragTrap_2.getAttackDamage());
    FragTrap_2.attack("FragTrap_1");
    FragTrap_1.takeDamage(FragTrap_2.getAttackDamage());
    
    std::cout << FragTrap_1;
    std::cout << FragTrap_2;
    FragTrap_2 = FragTrap_1;
    std::cout << FragTrap_2;
}