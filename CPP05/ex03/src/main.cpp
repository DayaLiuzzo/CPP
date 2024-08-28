#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int	main(void)
{   

    std::cout << "--------------------------------" << std::endl;
    std::cout << "ShrubberyCreationForm correct" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        Intern i;
        AForm *f = i.makeForm("shrubbery creation", "Correct_shrubbery");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << " Incorrect form" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        Intern i;
        AForm *f = i.makeForm("", "target");
        b.signForm(*f);
        b.executeForm(*f);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "robotommy request correct" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        Intern i;
        AForm *f = i.makeForm("robotomy request", "Wendy Williams");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Presidential Pardon correct" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        Intern i;
        AForm *f = i.makeForm("presidential pardon", "Lisa Rina");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	return (0);
}