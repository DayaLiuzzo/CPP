#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
    std::cout << "---Bureaucrat---" << std::endl;
    std::cout << "Low Grade Exception" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 2);
        Form f("Form", 1, 1);
        b.signForm(f);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Correct Input" << std::endl;
    try
    {
    Bureaucrat b("Bureaucrat", 1);
    Form f("Form", 1, 1);
    b.signForm(f);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Low SignGrade form Exception" << std::endl;
    try
    {
    Bureaucrat b("Bureaucrat", 149);
    Form f("Form", 1498, 150);
    b.signForm(f);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Low ExecGrade form Exception" << std::endl;
    try
    {
    Bureaucrat b("Bureaucrat", 149);
    Form f("Form", 150, 1500);
    b.signForm(f);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Correct Input" << std::endl;
    try
    {
    Bureaucrat b("Bureaucrat", 1);
    Form f("Form", 2, 1);
    b.signForm(f);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "High SignGrade form Exception" << std::endl;
    try
    {
    Bureaucrat b("Bureaucrat", 1);
    Form f("Form", -1, 1);
    b.signForm(f);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
        std::cout << "--------------------------------" << std::endl;
    std::cout << "High ExecGrade form Exception" << std::endl;
    try
    {
    Bureaucrat b("Bureaucrat", 1);
    Form f("Form", 1, -1);
    b.signForm(f);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}