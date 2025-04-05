#include "Serializer.hpp"

Serializer::Serializer(){
    std::cout << "Default Serializer Constructor called !" << std::endl;
}

Serializer::~Serializer(){
    std::cout << "Default Serializer Destructor called !" << std::endl;
}

Serializer::Serializer(const Serializer &assign){
    std::cout << "Serializer Copy Constructor called !" << std::endl;
}

Serializer& Serializer::operator=(const Serializer &assign){
    if (this != &assign){
        // Assignment logic here
    }
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr){

}

Data* Serializer::deserialize(uintptr_t raw){
    
}