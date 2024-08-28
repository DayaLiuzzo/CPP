#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
private:
    // Class members go here
    const std::string _name;
    const int _signGrade;
    const int _execGrade;
    bool _isSigned;
public:
    AForm &operator=(const AForm &other); // Copy assignment operator
    AForm(); // Default constructor
    AForm(const AForm &other); // Copy constructor
    AForm(std::string name, int signGrade, int execGrade); // Parametric constructor
    virtual ~AForm(); // Destructor

    //member functions
    void beSigned(Bureaucrat &bureaucrat);
    void execute(Bureaucrat const & executor) const;
    virtual void action(Bureaucrat const & executor) const = 0;

    //getters & setters
    int getSignGrade() const;
    int getExecGrade() const;
    bool getIsSigned() const;
    std::string getName() const;

    //exceptions
    class GradeTooHighException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class FormNotSigned : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};

std::ostream& operator<<(std::ostream &os, const AForm &Aform);

#endif // FORM_HPP

