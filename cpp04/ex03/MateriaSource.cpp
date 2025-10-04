#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; i++)
        this->templates[i] = NULL;
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; i++)
        delete templates[i];
}

MateriaSource::MateriaSource(const MateriaSource &assign){
    for (int i = 0; i < 4; i++)
        this->templates[i] = (assign.templates[i] ? assign.templates[i]->clone() : NULL);
}

MateriaSource& MateriaSource::operator=(const MateriaSource &assign){
    if(this != &assign){
        for (int i = 0; i < 4; i++)
        {
            if (this->templates[i])
                delete this->templates[i];
            this->templates[i] = (assign.templates[i] ? assign.templates[i]->clone() : NULL);
        }
    }
    return *this;
}

void    MateriaSource::learnMateria(AMateria* materia){
    if (!materia)
    return ;
    for (int i = 0; i < 4; i++){
        if (!templates[i]){
            templates[i] = materia;
            return ;
        } 
    }
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++){
        if (templates[i] && templates[i]->getType() == type){
            return templates[i]->clone();
        }
    }
    return NULL;
}


