#include "inc/ClassTest.hpp"
#include "utils.hpp"

ClassTest::ClassTest() 
{
    std::cout << GREEN_COLOR << "ClassTest default constructor called" << RESET_COLOR << std::endl;
}

ClassTest::ClassTest(const ClassTest &other) 
{
    std::cout << GREEN_COLOR << "ClassTest copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

ClassTest &ClassTest::operator=(const ClassTest &other) 
{
    std::cout << GREEN_COLOR << "ClassTest copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
        // Copy the data from 'other' to 'this'
    }
    return *this;
}

ClassTest::~ClassTest() 
{
    std::cout << GREEN_COLOR << "ClassTest destructor called" << RESET_COLOR << std::endl;
}

