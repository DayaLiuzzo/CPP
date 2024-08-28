#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
private:
    // Class members go here
    std::string _target;
public:
    PresidentialPardonForm(); // Default constructor
    PresidentialPardonForm(const PresidentialPardonForm &other); // Copy constructor
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other); // Copy assignment operator
    ~PresidentialPardonForm(); // Destructor
    PresidentialPardonForm(std::string target); // Parametric constructor
    void action(Bureaucrat const & executor) const;
};

#endif // PRESIDENTIALPARDONFORM_HPP

