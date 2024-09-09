#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <algorithm>


template <typename T>
class MutantStack : public std::stack<T>
{
private:
    // Class members go here
public:
    MutantStack(const std::stack<T>& other) : std::stack<T>(other) {}
    MutantStack(){}
    MutantStack(const MutantStack &other) : std::stack<T>(other){}
    MutantStack &operator=(const MutantStack &other){
        if (this != &other) {
            std::stack<T>::operator=(other); 
        }
        return *this;
    }
    ~MutantStack(){}; // Destructor

    typedef typename std::stack<T>::container_type::iterator iterator;
    
    // Member functions go here
    void push(const T &value)
    {
        std::stack<T>::push(value);
    }

    void pop()
    {
        std::stack<T>::pop();
    }

    T top() const
    {
        return std::stack<T>::top();
    }

    size_t size() const
    {
        return std::stack<T>::size();
    }
    iterator begin()
    {
        return std::stack<T>::c.begin();
    }

    iterator end()
    {
        return std::stack<T>::c.end();
    }

};

#endif // MUTANTSTACK_HPP

