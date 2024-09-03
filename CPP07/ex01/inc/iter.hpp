#include "utils.hpp"


template <typename T>
void iter(T *array, size_t size, void (*f)(T const &))
{
    for (size_t i = 0; i < size; i++)
        f(array[i]);
}

template<typename T>
void test(T const &t)
{
    std::cout << t << std::endl;
}