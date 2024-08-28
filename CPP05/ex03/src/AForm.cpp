#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "utils.hpp"

//Constructors
AForm::AForm() : _name("Default"), _signGrade(150), _execGrade(150), _isSigned(false) 
{
    std::cout << GREEN_COLOR << "AForm Default constructor called" << RESET_COLOR << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade) ,  _isSigned(other._isSigned)
{
    std::cout << GREEN_COLOR << "AForm copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}
AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false) 
{
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    std::cout << GREEN_COLOR << "AForm constructor called" << RESET_COLOR << std::endl;
}

//Operators

std::ostream &operator<<(std::ostream &os, const AForm &Aform) 
{
    os << "AForm: " << Aform.getName() << " is signed: " << Aform.getIsSigned() << " Sign grade: " << Aform.getSignGrade() << " Exec grade: " << Aform.getExecGrade();
    return os;
}

AForm &AForm::operator=(const AForm &other)
{
    std::cout << GREEN_COLOR << "Form assignation operator called" << RESET_COLOR << std::endl;
    if(this == &other)
        return *this;
    return *this;
}

//getters & setters
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecGrade() const { return _execGrade; }
bool AForm::getIsSigned() const { return _isSigned; }
std::string AForm::getName() const { return _name; }

//member functions
void AForm::beSigned(Bureaucrat &bureaucrat) 
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    if (!_isSigned)
        throw FormNotSigned();
    action(executor);
}

//destructor
AForm::~AForm() 
{
    std::cout << RED_COLOR << "AForm destructor called" << RESET_COLOR << std::endl;
}

//exceptions
const char *AForm::GradeTooHighException::what() const throw()
{   
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *AForm::FormNotSigned::what() const throw()
{
    return "Form is not signed";
}

