#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cstddef>
#include <vector>
#include <iterator>
#include <iomanip>


class Span {
private:
    std::vector<int> _data;
    unsigned int _size;
public:
    Span(); // Default constructor
    Span(const Span &other);
    Span(unsigned int size); // Parametric constructor
    Span &operator=(const Span &other);
    ~Span(); // Destructor

    //member functions
    void addNumber(int n);
    int shortestSpan() const;
    int longestSpan() const;
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    void display_data() const;
};  

#endif // SPAN_HPP

