#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>

class Cat : public Animal
{
  private:
	Brain *brain;
	// Class members go here
  public:
	Cat();                            // Default constructor
	Cat(const Cat &other);            // Copy constructor
	Cat &operator=(const Cat &other); // Copy assignment operator
	~Cat();                           // Destructor
	void makeSound() const;
	std::string getBrainIdea(int index) const;
    void setBrainIdea(int index, std::string idea);
  protected:
	std::string type;
};

#endif // CAT_HPP
