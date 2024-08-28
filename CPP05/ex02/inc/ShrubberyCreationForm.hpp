#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
private:
    // Class members go here
    std::string _target;
public:
    ShrubberyCreationForm(); // Default constructor
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other); // Copy assignment operator
    ShrubberyCreationForm(const ShrubberyCreationForm &other); // Copy constructor
    ShrubberyCreationForm(std::string target); // Parametric constructor
    ~ShrubberyCreationForm(); // Destructor

    void action(Bureaucrat const & executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP

