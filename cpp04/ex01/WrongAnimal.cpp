#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    this->type = "none";
    std::cout << "Constructor WrongAnimal called !" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Destructor WrongAnimal called !" << std::endl;
}
    
WrongAnimal::WrongAnimal(const WrongAnimal &assign){
    this->type = assign.type;
}
    
WrongAnimal&   WrongAnimal::operator=(const WrongAnimal &assign){
    if (this != &assign){
        this->type = assign.type;
    }
    return *this;
}

void    WrongAnimal::makeSound() const {
    std::cout << "No sound founded !" << std::endl;
}

std::string     WrongAnimal::getType() const { return this->type; };
