#include "BitcoinExchange.hpp"

bool is_date(const std::string &line)
{
    std::stringstream ss(line);
    std::string date;
    if(std::getline(ss, date, '|'))
    {
        date = trim(date);
        if(date.size() != 10)
            return (error_msg("bad input => " + line));
        for(int i = 0; i < 10; i++)
        {
            if(i == 4 || i == 7)
            {
                if(date[i] != '-')
                    return (error_msg("bad input => " + line));
            }
            else if(!isdigit(date[i]))
                return (error_msg("bad input => " + line));
        }
        return true;
    }
    return (error_msg("bad input => " + line));
}
bool is_correct_date(const std::string &date)
{
    std::stringstream ss(date);
    std::string year, month, day;
    if (std::getline(ss, year, '-') && std::getline(ss, month, '-') && std::getline(ss, day, '-')) 
    {
        int month_num = std::atoi(month.c_str());
        int day_num = std::atoi(day.c_str());
        int year_int = std::atoi(year.c_str());

        if (month_num >= 1 && month_num <= 12 && day_num >= 1 && day_num <= 31) {
            if((month_num == 4 || month_num == 6 || month_num == 9 || month_num == 11) && day_num > 30)
                return (error_msg("bad input => " + date));
            if(month_num == 2 && day_num > 29)
                return (error_msg("bad input => " + date));
            if(month_num == 2 && day_num == 29 && ((year_int % 4 != 0 || year_int % 100 == 0 )&& (year_int % 400 != 0)))
                return (error_msg("bad input => " + date));
            return true;
        }
    }

    return (error_msg("bad input => " + date));
}

bool is_number(const std::string &line)
{
    std::stringstream ss(line);
    std::string date;
    std::string number;
    if(std::getline(ss, date, '|') && std::getline(ss, number))
    {
        number = trim(number);
        char *end;
        double test;
        test = std::strtod(number.c_str(), &end);
        if(*end == '\0')
            return true;
        else if(*end == 'f' && isFloat(number))
                return true;
        else 
            return (error_msg("bad input => " + line));
    }
    return (error_msg("bad input => " + line));
}
bool is_correct_number(const std::string &line)
{
    double num = get_number(line);
    if (num <= 1000 && num >= 0)
        return true;
    else if (num < 0)
        return (error_msg("not a positive integer"));
    else if (num > 1000)
        return (error_msg("too large a number"));
    return (error_msg("bad input => " + line));
}

bool can_open_file(const std::string &filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        return false;
    }
    file.close();
    return true;
}

bool isFloat(std::string input)
{
    int point = 0;
    int f = 0;
    size_t i = 0;
    if (std::isnan(std::atof(input.c_str())) || std::isinf(std::atof(input.c_str())))
        return false;
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