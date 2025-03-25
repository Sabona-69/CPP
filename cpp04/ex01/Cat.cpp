#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    this->brain = new Brain; 
    std::cout << "Constructor Cat called !" << std::endl;
}
    
Cat::~Cat(){
    delete brain;
    std::cout << "Destructor Cat called !" << std::endl;
}
    
Cat::Cat(const Cat &assign) : Animal(assign){
}
    
Cat&   Cat::operator=(const Cat &assign){
    if (this != &assign){
        this->type = assign.type;
    }
    return *this;
}
    
void    Cat::makeSound() const{
    std::cout << "Cat sound !" << std::endl;
}
