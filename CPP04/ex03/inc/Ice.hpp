#ifndef ICE_HPP
#define ICE_HPP


#include "AMateria.hpp"

class Ice : public AMateria
{
private:
    // Class members go here
public:
    Ice(); // Default constructor
    Ice(const Ice &other); // Copy constructor
    Ice &operator=(const Ice other); // Copy assignment operator
    virtual ~Ice(); // Destructor

    void use(ICharacter &target);
    virtual AMateria *clone() const;
};

#endif // ICE_HPP

