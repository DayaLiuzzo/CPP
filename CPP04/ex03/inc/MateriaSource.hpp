#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _materias[4];
public:
    MateriaSource(); // Default constructor
    MateriaSource(const MateriaSource &other); // Copy constructor
    virtual ~MateriaSource(); // Destructor

    //operators
    MateriaSource &operator=(MateriaSource other); // Copy assignment operator
    void swap(MateriaSource &first, MateriaSource &second);

    // member functions
	virtual void learnMateria(AMateria *);
	virtual AMateria *createMateria(std::string const &type);
};

#endif // MATERIASOURCE_HPP

