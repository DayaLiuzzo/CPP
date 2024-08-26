#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"


class Cure : public AMateria
{
private:
    // Class members go here
public:
    Cure(); // Default constructor
    Cure(const Cure &other); // Copy constructor
    Cure &operator=(const Cure other); // Copy assignment operator
    virtual ~Cure(); // Destructor

    void use(ICharacter &target);
    virtual AMateria *clone() const;
};

#endif // CURE_HPP

