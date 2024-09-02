#include "Serializer.hpp"

Serializer::Serializer() 
{
    std::cout << GREEN_COLOR << "Serializer default constructor called" << RESET_COLOR << std::endl;
}

Serializer::Serializer(const Serializer &other) 
{
    std::cout << GREEN_COLOR << "Serializer copy constructor called" << RESET_COLOR << std::endl;
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other) 
{
    std::cout << GREEN_COLOR << "Serializer copy assignment operator called" << RESET_COLOR << std::endl;
    if (this != &other) {
        // Copy the data from 'other' to 'this'
    }
    return *this;
}

Serializer::~Serializer() 
{
    std::cout << GREEN_COLOR << "Serializer destructor called" << RESET_COLOR << std::endl;
}



uintptr_t Serializer::serialize(Data* ptr)
{
    std::cout << GREEN_COLOR << "Serializer serialize method called" << RESET_COLOR << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}


Data* Serializer::deserialize(uintptr_t raw)
{
    std::cout << GREEN_COLOR << "Serializer deserialize method called" << RESET_COLOR << std::endl;
    return reinterpret_cast<Data*>(raw);
}