#include "BitcoinExchange.hpp"



void print_data(const std::map<std::string, double>& data_base) 
{
    std::cout << std::fixed << std::setprecision(10); // Use high precision (10 decimal places)
    
    for (std::map<std::string, double>::const_iterator it = data_base.begin(); it != data_base.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}

int decimalNumbers(std::string input)
{
    size_t i = 0;
    int decimalNumbers = 0;
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

int dateToInt(const std::string& date) {
    std::string numDate = date;
    numDate.erase(std::remove(numDate.begin(), numDate.end(), '-'), numDate.end()); // Remove dashes
    return atoi(numDate.c_str());  // Convert to integer using atoi in C++98
}

std::string get_date(const std::string &line)
{
    std::stringstream ss(line);
    std::string date;
    std::string number;
    std::getline(ss, date, '|');
    date = trim(date);
    return date;
}

double get_number(const std::string &line)
{
    std::stringstream ss(line);
    std::string date;
    std::string number;
    std::getline(ss, date, '|');
    std::getline(ss, number);
    number = trim(number);
    char *end;
    double test;
    test = std::strtod(number.c_str(), &end);
    return test;
}

std::string get_number_str(const std::string &line)
{
    std::stringstream ss(line);
    std::string date;
    std::string number;
    std::getline(ss, date, '|');
    std::getline(ss, number);
    number = trim(number);
    return number;
}


bool error_msg(const std::string &line)
{
    std::cerr << RED_COLOR << "Error: " << line << RESET_COLOR << std::endl;
    return false;
}

std::string trim(const std::string &str) {
    const char *ws = " \t\n\r\f\v";
    std::string s = str;
    s.erase(0, s.find_first_not_of(ws));
    s.erase(s.find_last_not_of(ws) + 1);
    return s;
}
