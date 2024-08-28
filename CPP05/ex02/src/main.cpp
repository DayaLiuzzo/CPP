#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "ShrubberyCreationForm Grade to low to execute" << std::endl;
    try
    {
		Bureaucrat b("Bureaucrat", 150);
		ShrubberyCreationForm s("ShrubberyCreationForm");
		b.signForm(s);
		b.executeForm(s);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "ShrubberyUnsigned" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
		ShrubberyCreationForm s("INCORRECT_FILE");
		b.executeForm(s);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "--------------------------------" << std::endl;
    std::cout << "ShrubberyCreationForm Correct" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        ShrubberyCreationForm s("file_name");
        b.signForm(s);
        b.executeForm(s);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "PresidentialPardonForm Grade to low to execute" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 150);
        PresidentialPardonForm p("PresidentialPardonForm");
        b.signForm(p);
        b.executeForm(p);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "PresidentialPardonForm Correct" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        PresidentialPardonForm p("Lisa Rina");
        b.signForm(p);
        b.executeForm(p);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "RobotomyRequestForm Grade to low to execute" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 150);
        RobotomyRequestForm r("Wendy Williams");
        b.signForm(r);
        b.executeForm(r);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "RobotomyRequestForm Correct" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        RobotomyRequestForm r("Wendy Williams");
        b.signForm(r);
        b.executeForm(r);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
	return (0);
}