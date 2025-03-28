#include "Ice.hpp" 

Ice::Ice() : AMateria("ice") {
}

Ice::~Ice(){
}

Ice::Ice(const Ice &assign) :  AMateria(assign){
}

Ice&   Ice::operator=(const Ice &assign){
    if (this != &assign){
        this->type = assign.type;
    }
    return *this;
}

void    Ice::use(ICharacter& target){
    
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n"; 
}

Ice*   Ice::clone() const{
    return new Ice();
}
