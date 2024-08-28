#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "utils.hpp"

//Constructors
Form::Form() : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false) 
{
    std::cout << GREEN_COLOR << "Form Default constructor called" << RESET_COLOR << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade) ,  _isSigned(other._isSigned)
{
    std::cout << GREEN_COLOR << "Form copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) 
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << GREEN_COLOR << "Form constructor called" << RESET_COLOR << std::endl;
}

//Operators
Form &Form::operator=(const Form &other)
{
    std::cout << GREEN_COLOR << "Form assignation operator called" << RESET_COLOR << std::endl;
    if(this == &other)
        return *this;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &form) 
{
    os << "Form: " << form.getName() << " is signed: " << form.getIsSigned() << " Sign grade: " << form.getSignGrade() << " Exec grade: " << form.getExecGrade();
    return os;
}

//getters & setters
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }
bool Form::getIsSigned() const { return _isSigned; }
std::string Form::getName() const { return _name; }

//member functions
void Form::beSigned(Bureaucrat &bureaucrat) 
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}
//destructor
Form::~Form() 
{
    std::cout << RED_COLOR << "Form destructor called" << RESET_COLOR << std::endl;
}

//exceptions
const char *Form::GradeTooHighException::what() const throw()
{   
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

