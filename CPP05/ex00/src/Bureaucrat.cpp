#include "Bureaucrat.hpp"
#include "utils.hpp"
#include <stdexcept>

//constructor
Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
    std::cout << GREEN_COLOR << "Bureaucrat Default constructor called" << RESET_COLOR << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name + "_copy"), _grade(other._grade)
{
    std::cout << GREEN_COLOR << "Bureaucrat copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    std::cout << GREEN_COLOR << "Bureaucrat constructor called" << RESET_COLOR << std::endl;
}
//operators
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) 
{
    std::cout << GREEN_COLOR << "Bureaucrat assignation operator called" << RESET_COLOR << std::endl;
    if(this == &other)
        return *this;
    this->_grade = other._grade;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
    os << YELLOW_COLOR << bureaucrat.getName() << " bureaucrat grade " << bureaucrat.getGrade() << RESET_COLOR << std::endl;
    return os;
}

//methods
void Bureaucrat::Promote()
{
    if (_grade == 1)
        throw GradeTooHighException();
    _grade--;
}
void Bureaucrat::Demote()
{
    if (_grade == 150)
        throw GradeTooLowException();
    _grade++;
}

//exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{   
    return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

//getters & setters
const std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

//destructors
Bureaucrat::~Bureaucrat() 
{
    std::cout << RED_COLOR << "Bureaucrat destructor called" << RESET_COLOR << std::endl;
}

