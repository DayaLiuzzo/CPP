#include "PmergeMe.hpp"

int main(int ac, char **av)
{

    // std::cout << "Input tests and Canonical Form check"

    PmergeMe merge_insert_sort;
    try{
    merge_insert_sort.execute(ac, av);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    // vector_pair vp;
    // deque_pair dp;
    // if(!checkMerge(ac, av, dm, vm))
    //     return 1;
    // std::vector<std::pair<int, int> >::iterator left = vm.begin();
    // std::vector<std::pair<int, int> >::iterator right = vm.end();
    // sort_pairs(vm);
    // print(vm);

}