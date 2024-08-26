#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    // Class members go here
    std::string _name;
    AMateria *_inventory[4];
    static AMateria *_floor[4];

public:
    Character(); // Default constructor
    Character(std::string name); // Parameterized constructor
    Character(const Character &other); // Copy constructor
    Character &operator=(const Character &other); // Copy assignment operator
    void swap(Character &first, Character &second);
    virtual ~Character(); // Destructor

    // Member functions
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);
};

#endif // CHARACTER_HPP

