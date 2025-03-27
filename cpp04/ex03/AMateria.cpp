#include "AMateria.hpp"

AMateria::AMateria(){
    std::cout << "Default AMateria Constructor called !" << std::endl;
    
}

AMateria::~AMateria(){
    std::cout << "Default AMateria Destructor called !" << std::endl;
    
}

AMateria::AMateria(std::string const &type) : type(type){};


AMateria::AMateria(const AMateria &assign) : type(assign.type){
    std::cout << "AMateria Copy Constructor called !" << std::endl;
}


AMateria&   AMateria::operator=(const AMateria &assign){
    if (this != &assign){
        this->type = assign.type;
        
    }
    return *this;
}

void AMateria::use(ICharacter& target){
    std::cout << "Nothing here to use !\n" ;
};


std::string const& AMateria::getType() const {
    return this->type;
}

