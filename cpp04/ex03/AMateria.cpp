#include "AMateria.hpp"

AMateria::AMateria(){
    std::cout << "Default AMateria Constructor called !" << std::endl;
    
}

AMateria::~AMateria(){
    std::cout << "Default AMateria Destructor called !" << std::endl;
    
}

AMateria::AMateria(std::string const &type){
    this->type = type;
};


AMateria::AMateria(const AMateria &assign){
    
    std::cout << "AMateria Copy Constructor called !" << std::endl;
}


AMateria&   AMateria::operator=(const AMateria &assign){
    if (this != &assign){
        ;
    }
    return *this;
}

AMateria::AMateria(std::string const & type){

}

void AMateria::use(ICharacter& target){
    std::cout << "Nothing here to use !\n" ;
};


std::string const& AMateria::getType() const {
    return this->type;
}

