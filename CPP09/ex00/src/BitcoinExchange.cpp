#include "BitcoinExchange.hpp"

int validate_input_files(int ac, char **av)
{
    if (ac != ARGUMENTS)
    {
        std::cerr << "Usage: " << av[0] << " <filename>" << std::endl;
        return 1;
    }
    if (!can_open_file(av[FILENAME]) || !can_open_file("data.csv"))
    {
        std::cerr << "Error: cannot open file " << std::endl;
        return 1;
    }
    return 0;
}
void read_data(std::map<std::string, double> &myMap, const std::string &filename, const char sep)
{
    std::ifstream file(filename.c_str());
    std::string line;

    while(std::getline(file, line))
    {
        line = trim(line);
        std::stringstream ss(line);
        std::string key;
        double value;
        if(std::getline(ss, key, sep) && ss >> value)
        {
           myMap[key] = value;
        }
    }
}

std::string find_closest_date(std::map<std::string, double> &data_map, const std::string &date)
{
    int target = dateToInt(date);
    std::string closestDate;
    int minDifference = -1;

    for (std::map<std::string, double>::const_iterator it = data_map.begin(); it != data_map.end(); ++it) {
        int current = dateToInt(it->first);
        if(current <= target)
        {
            int diff = target - current;
            if (minDifference == -1 || diff < minDifference) {
                minDifference = diff;
                closestDate = it->first;
            }
        }
    }

    return closestDate;
}

void bitcoin_rate_at(const std::string &line, std::map<std::string, double> &data_map)
{
    std::string date = get_date(line);
    double number = get_number(line);
    std::string closest_date = find_closest_date(data_map, date);
    double value = number * data_map[closest_date];
    std::cout << date << " => " << get_number_str(line) << " = " << value << std::endl;

}

void compare_data(const std::string &input_filename, std::map<std::string, double> &data_map) 
{
    std::ifstream file(input_filename.c_str());
    std::string line;
    while(std::getline(file, line))
    {
        line = trim(line);
        if(is_date(line) && is_correct_date(line) && is_number(line) && is_correct_number(line))
            bitcoin_rate_at(line, data_map);
    }
}
