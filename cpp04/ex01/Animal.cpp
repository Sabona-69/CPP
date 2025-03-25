#include "Animal.hpp"

Animal::Animal(){
    this->type = "none";
    std::cout << "Constructor Animal called !" << std::endl;
}
    
Animal::~Animal(){
    std::cout << "Destructor Animal called !" << std::endl;
}
    
Animal::Animal(const Animal &assign){
    this->type = assign.type;
}
    
Animal&   Animal::operator=(const Animal &assign){
    if (this != &assign){
        this->type = assign.type;
    }
    return *this;
}
    
void    Animal::makeSound() const {
    std::cout << "No sound founded !" << std::endl;
}

std::string     Animal::getType() const { return this->type; };


void     Animal::set_Brain(std::string& str, int index){
    this->ideas[index] = str;
}