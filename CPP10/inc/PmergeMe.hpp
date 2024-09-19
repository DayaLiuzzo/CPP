#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define ODD 2147483647
#include <iostream>
#include <sstream>
#include <limits>
#include <set>
#include <deque>
#include <vector>
#include <iterator>
#include <algorithm>


#define TEST_SUCCESS "Valid Input: "
#define YELLOW_COLOR "\033[38;2;236;245;66m"
#define LILAC_COLOR "\033[38;2;182;126;222m"
#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[38;2;201;59;40m"
#define GREEN_COLOR "\033[38;2;50;227;79m"


typedef std::vector<std::pair<int, int> > vector_pair;
typedef std::deque<std::pair<int, int> > deque_pair;


class PmergeMe {
protected:
    std::deque<int> deque;
    std::vector<int> vector;
    std::vector<std::string> strings;

    bool init_containers(int ac, char **av);
    bool has_duplicates();
public:
    bool _isOdd;
    int odd;
    PmergeMe();
    PmergeMe(PmergeMe const &other);
    PmergeMe& operator=(PmergeMe const& other);
    // Destructor
    virtual ~PmergeMe();
    
    void execute(int ac, char **av);
};


#endif // PMERGEME_HPP