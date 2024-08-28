#include "ShrubberyCreationForm.hpp"
#include "utils.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
    std::cout << GREEN_COLOR << "ShrubberyCreationForm Default constructor called" << RESET_COLOR << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
    std::cout << GREEN_COLOR << "ShrubberyCreationForm copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << GREEN_COLOR << "ShrubberyCreationForm constructor called" << RESET_COLOR << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << GREEN_COLOR << "ShrubberyCreationForm assignation operator called" << RESET_COLOR << std::endl;
    if(this == &other)
        return *this;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() 
{
    std::cout << RED_COLOR << "ShrubberyCreationForm destructor called" << RESET_COLOR << std::endl;
}

void ShrubberyCreationForm::action(Bureaucrat const & executor) const
{
    if (executor.getGrade() > getExecGrade())
        throw GradeTooLowException();
    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Couldn't open file");
    file << "       _-_\n    /~~   ~~\\\n /~~         ~~\\\n{               }\n \\  _-     -_  /\n   ~  \\ //  ~\n_- -   | | _- _\n  _ -  | |   -_\n      // \\\n";
    file.close();
}

