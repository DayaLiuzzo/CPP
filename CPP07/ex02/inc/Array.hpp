#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
private:
    T *_array;
    size_t _size;

public:
    Array() : _size(0), _array(new T[0]) {};
    Array(unsigned int size) : _array(new T[size]), _size(size) {};
    Array(const Array &other)
    {
        _size = other._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _array[i] = other._array[i];
    };

    Array &operator=(const Array &other)
    {
        if (this == &other)
            return *this;
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (size_t i = 0; i < _size; i++)
            _array[i] = other._array[i];
        return *this;
    };

    ~Array()
    {
        delete[] _array;
    };

    T &operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of range");
        return _array[index];
    };

    size_t capacity()
    {
        return _size;
    };

    size_t size()
    {
        return _size;
    };
};

#endif // ARRAY_HPP

