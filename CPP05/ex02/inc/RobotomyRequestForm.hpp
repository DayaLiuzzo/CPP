#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "AForm.hpp"
class Bureaucrat;

class RobotomyRequestForm : public AForm {
private:
    // Class members go here
    std::string _target;
public:
    RobotomyRequestForm(); // Default constructor
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other); // Copy assignment operator
    RobotomyRequestForm(const RobotomyRequestForm &other); // Copy constructor
    RobotomyRequestForm(std::string target); // Parametric constructor
    ~RobotomyRequestForm(); // Destructor
    void action(Bureaucrat const & executor) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP

