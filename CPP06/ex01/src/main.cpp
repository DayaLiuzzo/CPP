#include "Serializer.hpp"

int main()
{
    Data data;
    data.value = 42;

    std::cout << "Original data: " << data.value << std::endl;
    std::cout << "Original data address: " << &data << std::endl;

    uintptr_t serializedData = Serializer::serialize(&data);
    std::cout << "serialized data: " << serializedData << std::endl;

    Data* deserializedData = Serializer::deserialize(serializedData);
    std::cout << "Deserialized data address: " << deserializedData << std::endl;
    std::cout << "Deserialized data: " << deserializedData->value << std::endl;

}