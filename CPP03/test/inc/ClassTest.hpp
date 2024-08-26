#ifndef CLASSTEST_HPP
#define CLASSTEST_HPP

#include <iostream>

class ClassTest {
private:
    // Class members go here
public:
    ClassTest(); // Default constructor
    ClassTest(const ClassTest &other); // Copy constructor
    ClassTest &operator=(const ClassTest &other); // Copy assignment operator
    ~ClassTest(); // Destructor
};

#endif // CLASSTEST_HPP

