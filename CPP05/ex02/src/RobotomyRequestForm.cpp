#include "RobotomyRequestForm.hpp"
#include "utils.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
    std::cout << GREEN_COLOR << "RobotomyRequestForm Default constructor called" << RESET_COLOR << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) 
{
    std::cout << GREEN_COLOR << "RobotomyRequestForm copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << GREEN_COLOR << "RobotomyRequestForm constructor called" << RESET_COLOR << std::endl;
}
RobotomyRequestForm::~RobotomyRequestForm() 
{
    std::cout << RED_COLOR << "RobotomyRequestForm destructor called" << RESET_COLOR << std::endl;
}

void RobotomyRequestForm::action(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::cout << "*Bzzzz DRRrrrrRR Krrr ZZZzzzzz* ";
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << _target << " robotomization failed" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << GREEN_COLOR << "RobotomyRequestForm assignation operator called" << RESET_COLOR << std::endl;
    if(this == &other)
        return *this;
    return *this;
}

