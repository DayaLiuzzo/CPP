#include "easyfind.h"
#include "utils.hpp"
#include <vector>
#include <list>

int main()
{   
    {
    std::vector<int> vec;
    for (int i = 0; i < 5; i++)
        vec.push_back(i);
    std::list<int> lst;
    for (int i = 10; i < 100; i+=10)
        lst.push_back(i);

    const std::vector<int> constVec = vec;
    const std::list<int> constLst = lst;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Element found: " << *it << std::endl;

        std::list<int>::iterator it2 = easyfind(lst, 90);
        std::cout << "Element found: " << *it2 << std::endl;

        easyfind(vec, 10);
    }
    catch (std::exception &e)
    {
        std::cerr << RED_COLOR << e.what() << RESET_COLOR << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << YELLOW_COLOR << "Trying with const containers" << RESET_COLOR << std::endl;
    try
    {
        std::vector<int>::const_iterator it = easyfind(constVec, 3);
        std::cout << "Element found: " << *it << std::endl;

        std::list<int>::const_iterator it2 = easyfind(constLst, 90);
        std::cout << "Element found: " << *it2 << std::endl;

        easyfind(vec, 10);
    }
    catch (std::exception &e)
    {
        std::cerr << RED_COLOR << e.what() << RESET_COLOR << std::endl;
    }
     std::cout << "--------------------------------------------" << std::endl;
    std::cout << YELLOW_COLOR << "Lst out of range" << RESET_COLOR << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Element found: " << *it << std::endl;

        std::list<int>::iterator it2 = easyfind(lst, 10);
        std::cout << "Element found: " << *it2 << std::endl;

        easyfind(lst, 100);
    }
    catch (std::exception &e)
    {
        std::cerr << RED_COLOR << e.what() << RESET_COLOR << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << YELLOW_COLOR << "Trying with const containers" << RESET_COLOR << std::endl;
    try
    {
        std::vector<int>::const_iterator it = easyfind(constVec, 4);
        std::cout << "Element found: " << *it << std::endl;

        std::list<int>::const_iterator it2 = easyfind(constLst, 10);
        std::cout << "Element found: " << *it2 << std::endl;

        easyfind(lst, 100);
    }
    catch (std::exception &e)
    {
        std::cerr << RED_COLOR << e.what() << RESET_COLOR << std::endl;
    }
    }

    {
    std::vector<int> vec;
    std::list<int> lst;

    const std::vector<int> constVec = vec;
    const std::list<int> constLst = lst;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << YELLOW_COLOR << "Lst Empty" << RESET_COLOR << std::endl;
    try
    {
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Element found: " << *it << std::endl;

        std::list<int>::iterator it2 = easyfind(lst, 10);
        std::cout << "Element found: " << *it2 << std::endl;

        easyfind(lst, 100);
    }
    catch (std::exception &e)
    {
        std::cerr << RED_COLOR << e.what() << RESET_COLOR << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << YELLOW_COLOR << "Trying with const containers" << RESET_COLOR << std::endl;
    try
    {
        std::vector<int>::const_iterator it = easyfind(constVec, 4);
        std::cout << "Element found: " << *it << std::endl;

        std::list<int>::const_iterator it2 = easyfind(constLst, 10);
        std::cout << "Element found: " << *it2 << std::endl;

        easyfind(lst, 100);
    }
    catch (std::exception &e)
    {
        std::cerr << RED_COLOR << e.what() << RESET_COLOR << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << YELLOW_COLOR << "Vec Empty" << RESET_COLOR << std::endl;
        try
    {
        std::vector<int>::iterator it = easyfind(vec, 4);
        std::cout << "Element found: " << *it << std::endl;

        std::list<int>::iterator it2 = easyfind(lst, 10);
        std::cout << "Element found: " << *it2 << std::endl;

        easyfind(lst, 100);
    }
    catch (std::exception &e)
    {
        std::cerr << RED_COLOR << e.what() << RESET_COLOR << std::endl;
    }
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << YELLOW_COLOR << "Trying with const containers" << RESET_COLOR << std::endl;
    try
    {
        std::list<int>::const_iterator it2 = easyfind(constLst, 10);
        std::cout << "Element found: " << *it2 << std::endl;
        std::vector<int>::const_iterator it = easyfind(constVec, 4);
        std::cout << "Element found: " << *it << std::endl;


        easyfind(vec, 1);
    }
    catch (std::exception &e)
    {
        std::cerr << RED_COLOR << e.what() << RESET_COLOR << std::endl;
    }
    }


}
