#include "AMateria.hpp"

AMateria::AMateria(){
    
}

AMateria::~AMateria(){
    
}

AMateria::AMateria(std::string const &type) : type(type){};


AMateria::AMateria(const AMateria &assign) : type(assign.type){
}


AMateria&   AMateria::operator=(const AMateria &assign){
    if (this != &assign){
        this->type = assign.type;
    }
    return *this;
}

void AMateria::use(ICharacter& target){
    (void)target;
};


std::string const& AMateria::getType() const {
    return this->type;
}

