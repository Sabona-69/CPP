#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    std::cout << "Default MateriaSource Constructor called !" << std::endl;
}

MateriaSource::~MateriaSource(){
    std::cout << "Default MateriaSource Destructor called !" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &assign){
    std::cout << "MateriaSource Copy Constructor called !" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &assign){
    if (this != &assign){
        // Assignment logic here
    }
    return *this;
}

void    MateriaSource::learnMateria(AMateria*){
    
}

AMateria* MateriaSource::createMateria(std::string const & type){

}


