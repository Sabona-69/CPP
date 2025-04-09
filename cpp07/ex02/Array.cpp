#include "Array.hpp"

Array::Array(){
    
    std::cout << "Default Array Constructor called !" << std::endl;
}

Array::~Array(){
    std::cout << "Default Array Destructor called !" << std::endl;
}

Array::Array(const Array &assign){
    std::cout << "Array Copy Constructor called !" << std::endl;
}

Array& Array::operator=(const Array &assign){
    if (this != &assign){
        // Assignment logic here
    }
    return *this;
}
