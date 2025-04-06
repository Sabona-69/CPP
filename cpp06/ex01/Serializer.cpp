#include "Serializer.hpp"

Serializer::Serializer(){
    std::cout << "Default Serializer Constructor called !" << std::endl;
}

Serializer::~Serializer(){
    std::cout << "Default Serializer Destructor called !" << std::endl;
}

Serializer::Serializer(const Serializer &assign){
    (void)assign;
    std::cout << "Serializer Copy Constructor called !" << std::endl;
}

Serializer& Serializer::operator=(const Serializer &assign){
    if (this != &assign){
        (void)assign;
        // Assignment logic here
    }
    return *this;
}

int     Serializer::getX() const {return this->x;}

uintptr_t Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}