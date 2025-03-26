#include "Cure.hpp" 

Cure::Cure(){
    std::cout << "Default Cure Constructor called !" << std::endl;
}

Cure::~Cure(){
    
    std::cout << "Default Cure Destructor called !" << std::endl;
}

Cure::Cure(const Cure &assign){
    
    std::cout << "Cure Copy Constructor called !" << std::endl;
}

Cure&   Cure::operator=(const Cure &assign){
    if (this != &assign){

    }
    return *this;
}

void    Cure::use(ICharacter& target){    
    std::cout << "* heals " << target.getName() << " ’s wounds *\n"; 
}

Cure*   Cure::clone() const{
    Cure    *cloned = new Cure();
    return cloned;
}
