#include <iostream>
#include "Serializer.hpp"


int main() {
    Data data;
    data.value = 42;

    Data* originalPtr = &data;

    uintptr_t raw = Serializer::serialize(originalPtr);

    Data* deserializedPtr = Serializer::deserialize(raw);

    std::cout << "Original address:     " << originalPtr << std::endl;
    std::cout << "Serialized uintptr_t: " << raw << std::endl;
    std::cout << "Deserialized address: " << deserializedPtr << std::endl;
    std::cout << "Value inside Data:    " << deserializedPtr->value << std::endl;

    return 0;
}
