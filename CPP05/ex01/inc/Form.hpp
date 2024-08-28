#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>


class Bureaucrat;

class Form {
private:
    // Class members go here
    const std::string _name;
    const int _signGrade;
    const int _execGrade;
    bool _isSigned;
public:
    Form(); // Default constructor
    Form(const Form &other); // Copy constructor
    Form(std::string name, int signGrade, int execGrade); // Parametric constructor
    Form &operator=(const Form &other); // Copy assignment operator
    ~Form(); // Destructor

    //member functions
    void beSigned(Bureaucrat &bureaucrat);

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
};

std::ostream& operator<<(std::ostream &os, const Form &form);

#endif // FORM_HPP

