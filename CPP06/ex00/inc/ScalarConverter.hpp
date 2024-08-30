#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
private:
    ScalarConverter(const ScalarConverter &other); // Copy constructor
    // Class members go here
    ScalarConverter(); // Default constructor
    ScalarConverter &operator=(const ScalarConverter &other); // Copy assignment operator
    ~ScalarConverter(); // Destructor
public:

    static void convert(const std::string &input);
};

//non member functions;
void	convertChar(std::string input);
void	convertInt(std::string input);
void	convertFloat(std::string input);
void	convertDouble(std::string input);

bool   isChar(std::string input);
bool   isInt(std::string input);
bool   isFloat(std::string input);
bool   isDouble(std::string input);


void displayChar(char char_input, int decimalNumbers);
void displayInt(int i, int decimalNumbers);
void displayFloat(float f, int decimalNumbers);
void displayDouble(double d, int decimalNumbers);

int get_int(std::string input);
char getChar(std::string input);
float getFloat(std::string input);
double getDouble(std::string input);

int decimalNumbers(std::string input);
#endif // SCALARCONVERTER_HPP

