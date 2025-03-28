#include "Cure.hpp" 

Cure::Cure() : AMateria("cure") {
}

Cure::~Cure(){
    
}

Cure::Cure(const Cure &assign) :  AMateria(assign){
}

Cure&   Cure::operator=(const Cure &assign){
    if (this != &assign){
        this->type = assign.type;
    }
    return *this;
}

void    Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "’s wounds *\n"; 
}


Cure*   Cure::clone() const{
    return new Cure();
}
