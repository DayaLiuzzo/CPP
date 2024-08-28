#include "Intern.hpp"
#include "utils.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern() 
{
    std::cout << GREEN_COLOR << "Intern default constructor called" << RESET_COLOR << std::endl;
}


AForm *Intern::makeForm(std::string formName, std::string target)
{
    const char* forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *form = NULL;
    for(int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << GREEN_COLOR << "Intern creates " << formName << " form" << RESET_COLOR << std::endl;
            switch (i)
            {
                case 0:
                    form = new ShrubberyCreationForm(target);
                    return form;
                case 1:
                    form = new RobotomyRequestForm(target);
                    return form;
                case 2:
                    form = new PresidentialPardonForm(target);
                    return form;
            }
        }
    }
        throw std::invalid_argument("Form not found");
    return form;
}

Intern::~Intern() 
{
    std::cout << RED_COLOR << "Intern destructor called" << RESET_COLOR << std::endl;
}

