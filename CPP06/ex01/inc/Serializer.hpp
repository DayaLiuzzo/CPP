#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <utils.hpp>

struct Data{
    int value;
};

class Serializer {
private:
    // Class members go here
    Serializer(); // Default constructor
    Serializer(const Serializer &other); // Copy constructor
    Serializer &operator=(const Serializer &other); // Copy assignment operator
    ~Serializer(); // Destructor
public:

    // Class methods go here
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);

};

#endif // SERIALIZER_HPP

