#include "PresidentialPardonForm.hpp"
#include "utils.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
    std::cout << GREEN_COLOR << "PresidentialPardonForm Default constructor called" << RESET_COLOR << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target)
{
    std::cout << GREEN_COLOR << "PresidentialPardonForm copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
    std::cout << GREEN_COLOR << "PresidentialPardonForm constructor called" << RESET_COLOR << std::endl;
}
PresidentialPardonForm::~PresidentialPardonForm() 
{
    std::cout << RED_COLOR << "PresidentialPardonForm destructor called" << RESET_COLOR << std::endl;
}

void PresidentialPardonForm::action(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << GREEN_COLOR << "PresidentialPardonForm assignation operator called" << RESET_COLOR << std::endl;
    if(this == &other)
        return *this;
    return *this;
}