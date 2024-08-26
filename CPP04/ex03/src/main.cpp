#include "utils.hpp"

int main()
{

    std::cout << "Classic Test" << std::endl;


IMateriaSource* src = new MateriaSource();
src->learnMateria(new Ice());
src->learnMateria(new Cure());
ICharacter* me = new Character("me");
AMateria* tmp;
tmp = src->createMateria("ice");
me->equip(tmp);
tmp = src->createMateria("cure");
me->equip(tmp);
ICharacter* bob = new Character("bob");
me->use(0, *bob);
me->use(1, *bob);

    IMateriaSource* src_2 = new MateriaSource();
    src_2->learnMateria(new Ice());
    ICharacter* me_2 = new Character("me_2");
    AMateria* tmp_2;
    tmp_2 = src_2->createMateria("ice");
    me_2->equip(tmp_2);
    AMateria* tmp_3;
    tmp_3 = src_2->createMateria("ice");
    me_2->equip(tmp_3);
    AMateria* tmp_4;
    tmp_4 = src_2->createMateria("ice");
    me_2->equip(tmp_4);
    AMateria* tmp_5;
    tmp_5 = src_2->createMateria("ice");
    me_2->equip(tmp_5);
    me_2->unequip(0);
    me_2->unequip(1);
    me_2->unequip(2);
    me_2->unequip(3);
    // AMateria* tmp_6;
    // tmp_6 = src_2->createMateria("ice");
    // me_2->equip(tmp_6);
    // me_2->unequip(0);

    ICharacter* bob_2 = new Character("bob_2");
    me_2->use(0, *bob_2);

    delete bob_2;
    delete me_2;
    delete src_2;

delete bob;
delete me;
delete src;

return 0;

}