#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
    private:
        AMateria* templates[4];
    public:
        MateriaSource();
        ~MateriaSource();
        MateriaSource(const MateriaSource &assign);
        MateriaSource& operator=(const MateriaSource &assign);
        void    learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif
