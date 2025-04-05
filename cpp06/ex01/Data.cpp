#include "Data.hpp"

Data::Data(){
    std::cout << "Default Data Constructor called !" << std::endl;
}

Data::~Data(){
    std::cout << "Default Data Destructor called !" << std::endl;
}

Data::Data(const Data &assign){
    std::cout << "Data Copy Constructor called !" << std::endl;
}

Data& Data::operator=(const Data &assign){
    if (this != &assign){
        // Assignment logic here
    }
    return *this;
}
