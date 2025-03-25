#include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->type = "WrongCat";
    std::cout << "Constructor WrongCat called !" << std::endl;
}
    
WrongCat::~WrongCat(){
    std::cout << "Destructor WrongCat called !" << std::endl;
}
    
WrongCat::WrongCat(const WrongCat &assign) : WrongAnimal(assign){
}
    
WrongCat&   WrongCat::operator=(const WrongCat &assign){
    if (this != &assign){
        this->type = assign.type;
    }
    return *this;
}
    
void    WrongCat::makeSound() const{
    std::cout << "WrongCat sound !" << std::endl;
}
