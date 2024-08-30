#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <sstream>
#include <cmath>
#include <iomanip>
#include <limits.h>
# define FAILURE 1

void ScalarConverter::convert(const std::string &input)
{
    if (input.empty())
    {
        print_message("Error: Empty input", RED_COLOR);
        return;
    }
    bool is_correct = true;
    if (isChar(input))
        displayChar(getChar(input), decimalNumbers(input));
    else if (isInt(input))
        displayInt(get_int(input), decimalNumbers(input));
    else if (isFloat(input))
       displayFloat(getFloat(input), decimalNumbers(input));
    else if(isDouble(input))
        displayDouble(getDouble(input), decimalNumbers(input));
    else
        is_correct = false;
    if(is_correct == false)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << input << "f" << std::endl;
        std::cout << input << std::endl;
        return;
    }
} 


//Non member functions
int decimalNumbers(std::string input)
{
    size_t i = 0;
    int decimalNumbers = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (;i < input.length(); i++)
    {
        if (input[i] == '.')
        {
            i++;
            for (;i < input.length(); i++)
            {
                if(isdigit(input[i]))
                    decimalNumbers++;
            }
            if(decimalNumbers <= 1)
                return 1;
            return decimalNumbers;
        }
    }
    if(decimalNumbers <= 1)
        return 1;
    return decimalNumbers;
}

//check type
bool isChar(std::string input)
{
    if (input.length() == 1)
        return true;
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'')
        return true;
    return false;
}
bool isInt(std::string input)
{
    long value;
    if (input.empty())
        return false;
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (;i < input.length(); i++)
    {
        if (!isdigit(input[i]))
            return false;
    }
    value = std::atol(input.c_str());
    if (value > INT_MAX || value < INT_MIN)
        return false;
    return true;
}
bool isFloat(std::string input)
{
    int point = 0;
    int f = 0;
    if (input.empty())
        return false;
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (;i < input.length(); i++)
    {
        if (input[i] == '.')
            point++;
        if (input[i] == 'f')
            f++;
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
            return false;
    }
    if (f == 1 && point == 1)
        return true;
    return false;
}
bool isDouble(std::string input)
{
    int point = 0;
    if (input.empty())
        return false;
    size_t i = 0;
    if (input[i] == '+' || input[i] == '-')
        i++;
    for (;i < input.length(); i++)
    {
        if (input[i] == '.')
            point++;
        if (!isdigit(input[i]) && input[i] != '.')
            return false;
    }
    if (point > 1)
        return false;
    return true;
}
// display
void displayChar(char char_input, int decimalNumbers)
{
    int f_decimal = decimalNumbers;
    int d_decimal = decimalNumbers;

    if (decimalNumbers > 6)
    {
        f_decimal = 6;
    }
    if (decimalNumbers > 15)
    {
        d_decimal = 15;
    }
    if (char_input < 32 || char_input > 126)
        print_message("char: Non displayable", RED_COLOR);
    else
        std::cout << "char: '" << char_input << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(char_input) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(f_decimal) << static_cast<float>(char_input) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(d_decimal) << static_cast<double>(char_input) << std::endl;
}
void displayInt(int i, int decimalNumbers)
{
    int f_decimal = decimalNumbers;
    int d_decimal = decimalNumbers;

    if (decimalNumbers > 6)
    {
        f_decimal = 6;
    }
    if (decimalNumbers > 15)
    {
        d_decimal = 15;
    }
    char c = static_cast<char>(i);
    if (c < 32 || c > 126)
        print_message("char: Non displayable", RED_COLOR);
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
  std::cout << "float: " << std::fixed << std::setprecision(f_decimal) << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(d_decimal) << static_cast<double>(i) << std::endl;
}

void displayFloat(float f, int decimalNumbers)
{
    int f_decimal = decimalNumbers;
    int d_decimal = decimalNumbers;

    if (decimalNumbers > 6)
    {
        f_decimal = 6;
    }
    if (decimalNumbers > 15)
    {
        d_decimal = 15;
    }
    char c = static_cast<char>(f);
    if (f < 32 || f > 126)
        print_message("char: Non displayable", RED_COLOR);
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if(f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
            print_message("int: impossible", RED_COLOR);
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(f_decimal) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(d_decimal) << static_cast<double>(f) << std::endl;;
}

void displayDouble(double d, int decimalNumbers)
{
    int f_decimal = decimalNumbers;
    int d_decimal = decimalNumbers;

    if (decimalNumbers > 6)
    {
        f_decimal = 6;
    }
    if (decimalNumbers > 15)
    {
        d_decimal = 15;
    }
    char c = static_cast<char>(d);
    if (d < 32 || d > 126)
        print_message("char: Non displayable", RED_COLOR);
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (d > INT_MAX || d < INT_MIN)
        print_message("int: impossible", RED_COLOR);
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(f_decimal) << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(d_decimal) << d << std::endl;
}
//get
char getChar(std::string str)
{
    if (str.length() == 1)
        return str[0] - 48;
    if (str.length() == 3 && str[0] == '\'' && str[2] == '\'')
        return str[1] - 48;
    return 0;
}

int get_int(std::string str)
{
    return (std::atoi(str.c_str()));
}

float getFloat(std::string str)
{
    return (std::atof(str.c_str()));
}
double getDouble(std::string str)
{
    return (std::atof(str.c_str()));
}