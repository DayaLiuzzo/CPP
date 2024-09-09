#include "Span.hpp"
#include "utils.hpp"

Span::Span() 
{
    std::cout << GREEN_COLOR << "Span default constructor called" << RESET_COLOR << std::endl;
}

Span::Span(unsigned int size) : _size(size)
{
    std::cout << GREEN_COLOR << "Span parametric constructor called" << RESET_COLOR << std::endl;
}

Span::Span(const Span &other) : _data(other._data)
{
        this->_size = other._size;
        // std::copy(other._data.begin(), other._data.end(), this->_data.begin());
}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        if(this->_size != other._size)
        {
            std::cerr << "Error: Span sizes are different" << std::endl;
            return *this;
        }
        std::copy(other._data.begin(), other._data.end(), this->_data.begin());
    }
    return *this;
}


Span::~Span() 
{
    std::cout << RED_COLOR << "Span destructor called" << RESET_COLOR << std::endl;
}

void Span::addNumber(int n)
{
    if (_data.size() >= _size)
        throw std::overflow_error("Span is full");
    _data.push_back(n);
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Span is empty or has only one element");
    std::vector<int> sorted = _data;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = sorted[1] - sorted[0];
    for (std::size_t i = 2; i < sorted.size(); i++)
    {
        int diff = sorted[i]- sorted[i-1];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::runtime_error("Span is empty or has only one element");
    
    int min_val = *std::min_element(_data.begin(), _data.end());
    int max_val = *std::max_element(_data.begin(), _data.end());

    return max_val - min_val;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_data.size() + std::distance(begin, end) > _size)
        throw std::overflow_error("Span is full");
    _data.insert(_data.end(), begin, end);
}

// int Span::at(std::size_t index) const
// {
//     if(index >= _data.size())
//         throw std::out_of_range("Index out of range");
//     return _data[index];
// }

    void Span::display_data() const
    {
        for (std::size_t i = 0; i < _data.size(); i++)
        {
            std::cout << "i: " << i << " " << _data[i] << std::endl;
        }
        std::cout << std::endl;
    }