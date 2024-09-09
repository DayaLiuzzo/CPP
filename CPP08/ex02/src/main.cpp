#include <MutantStack.hpp>
#include <stack>
#include <list>
#include <iostream>
#include <vector>

int main()
{
std::cout << "MutantStack" << std::endl;
std::cout << "Classic test" << std::endl;
    {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    }
std::cout << "---------------------" << std::endl;
std::cout <<"lst container" << std::endl;
    {
    std::list<int>  lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;
    lst.pop_back();
    std::cout << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    //[...]
    lst.push_back(0);
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int, std::list<int> > s(lst);
    }
{
std::cout << "---------------------" << std::endl;
std::cout << "vector container" << std::endl;

    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(17);

    // Use back to get the last element
    std::cout << vec.back() << std::endl;

    // Pop the last element
    vec.pop_back();

    // Print the size
    std::cout << vec.size() << std::endl;

    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(737);
    vec.push_back(0);

    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator ite = vec.end();

    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int, std::vector<int> > s(vec);
}

return 0;
}