#include <iostream>
#include "Serializer.hpp"


int main() {
    // Step 1: Create a Data instance
    Data originalData;
    originalData.value = 42;

    // Step 2: Get a pointer to originalData
    Data* originalPtr = &originalData;

    // Step 3: Serialize the pointer (convert to uintptr_t)
    uintptr_t raw = Serializer::serialize(originalPtr);

    // Step 4: Deserialize the raw uintptr_t (convert back to Data*)
    Data* deserializedPtr = Serializer::deserialize(raw);

    // Step 5: Verify
    std::cout << "Original address:     " << originalPtr << std::endl;
    std::cout << "Serialized uintptr_t: " << raw << std::endl;
    std::cout << "Deserialized address: " << deserializedPtr << std::endl;
    std::cout << "Value inside Data:    " << deserializedPtr->value << std::endl;

    return 0;
}
