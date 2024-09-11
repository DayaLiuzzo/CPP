#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <iomanip>
#include <cstdlib> 
#include <cmath>
#include <limits>
#include <algorithm>


#define YELLOW_COLOR "\033[38;2;236;245;66m"
#define LILAC_COLOR "\033[38;2;182;126;222m"
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[38;2;201;59;40m"
#define GREEN_COLOR "\033[38;2;50;227;79m"

#define ERROR 1
#define ARGUMENTS 2
#define FILENAME 1


//functions
int validate_input_files(int ac, char **av);
void bitcoin_rate_at(const std::string &line, std::map<std::string, double> &data_map);
void compare_data(const std::string &input_filename, std::map<std::string, double> &data_map);
void read_data(std::map<std::string, double> &myMap, const std::string &filename, const char sep);
std::string find_closest_date(std::map<std::string, double> &data_map, const std::string &date);

//utils
int decimalNumbers(std::string input);
int dateToInt(const std::string& date);
void print_data(const std::map<std::string, double>& data_base);
bool error_msg(const std::string &line);
double get_number(const std::string &line);
std::string get_date(const std::string &line);
std::string trim(const std::string &str);
std::string get_number_str(const std::string &line);

//checks
bool isFloat(std::string input);
bool is_date(const std::string &line);
bool is_correct_date(const std::string &date);
bool is_number(const std::string &line);
bool is_correct_number(const std::string &line);
bool can_open_file(const std::string &filename);


#endif // BITCOINEXCHANGE_HPP

