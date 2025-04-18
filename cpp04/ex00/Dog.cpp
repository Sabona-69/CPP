#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout << "Constructor Dog called !" << std::endl;
}

Dog::~Dog(){
    std::cout << "Destructor Dog called !" << std::endl;
}
    
Dog::Dog(const Dog &assign) : Animal(assign) {
}
    
Dog&   Dog::operator=(const Dog &assign){
    if (this != &assign){
        this->type = assign.type;
    }
    return *this;
}
    
void    Dog::makeSound() const{
    std::cout << "Dog sound !" << std::endl;
}

