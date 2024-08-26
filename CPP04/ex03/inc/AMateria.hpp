#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
#include <string>
#include "Character.hpp"
#include "MateriaSource.hpp"

class ICharacter;
class Character;
class MateriaSource;
class IMateriaSource;

class AMateria
{
  protected:
    std::string _type;
    Character *_character;
    MateriaSource *_materiaSource;

  public:
    AMateria();
    AMateria(const AMateria &other);
	AMateria(std::string const &type);
    virtual ~AMateria();

  //getters
  Character *getCharacter() const;
  MateriaSource *getMateriaSource() const;
	std::string const &getType() const; // Returns the materia type
  
  //setters
  void setCharacter(Character *character);
  void setMateriaSource(MateriaSource *materiaSource);
	
  
    virtual AMateria *clone() const = 0;
	  virtual void use(ICharacter &target) = 0;
    AMateria &operator=(const AMateria &other);
};

#endif // AMATERIA_HPP
