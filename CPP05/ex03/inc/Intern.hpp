#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern {
private:
    // Class members go here
    Intern(const Intern &other); // Copy constructor
    Intern &operator=(const Intern &other); // Copy assignment operator
public:
    Intern(); // Default constructor
    ~Intern(); // Destructor
    // Class methods go here
    AForm *makeForm(std::string formName, std::string target);
};

#endif // INTERN_HPP

