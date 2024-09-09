#include <algorithm>
#include <exception>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::runtime_error("Element not found");
    return it;
}

template <typename T>
typename T::const_iterator easyfind(const T  &container, int n)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::runtime_error("Element not found");
    return it;
}