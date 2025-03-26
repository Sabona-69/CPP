#include "Ice.hpp" 

Ice::Ice(){
    std::cout << "Default Ice Constructor called !" << std::endl;
}

Ice::~Ice(){
    
    std::cout << "Default Ice Destructor called !" << std::endl;
}

Ice::Ice(const Ice &assign){
    
    std::cout << "Ice Copy Constructor called !" << std::endl;
}

Ice&   Ice::operator=(const Ice &assign){
    if (this != &assign){

    }
    return *this;
}

void    Ice::use(ICharacter& target){
    
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n"; 
}

Ice*   Ice::clone() const{
    Ice    *cloned = new Ice();
    return cloned;
}
