#include "BitcoinExchange.hpp"

int main(int ac, char **av) 
{
    if(validate_input_files(ac, av))
        return(ERROR);
    std::map<std::string, double> data_base; 
    read_data(data_base, "data.csv", ',');
    compare_data(av[FILENAME], data_base);
    return 1;
}
