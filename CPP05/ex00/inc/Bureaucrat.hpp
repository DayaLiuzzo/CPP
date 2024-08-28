#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

    //cant copy const members, disabling default;
public:
    Bureaucrat &operator=(const Bureaucrat &other); // Copy assignment operator
    Bureaucrat(); // Default constructor
    Bureaucrat(const Bureaucrat &other); // Copy constructor
    Bureaucrat(const std::string &name, int grade); // Parameterized constructor
    ~Bureaucrat(); // Destructor

    //getters & setters
    const std::string getName() const;
    int getGrade() const;

    //methods
    void Promote();
    void Demote();

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

