#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>


class Form;

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

public:

    Bureaucrat(); // Default constructor
    Bureaucrat &operator=(const Bureaucrat &other); // Copy assignment operator
    Bureaucrat(const Bureaucrat &other); // Copy constructor
    Bureaucrat(const std::string &name, int grade); // Parameterized constructor
    ~Bureaucrat(); // Destructor

    //getters & setters
    const std::string getName() const;
    int getGrade() const;

    //methods
    void Promote();
    void Demote();
    void signForm(Form &form);

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
    std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif // BUREAUCRAT_HPP

