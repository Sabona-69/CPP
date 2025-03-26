#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria {
    public:
        Ice();
        ~Ice();
        Ice(const Ice &assign);
        Ice&   operator=(const Ice &assign);
        void    use(ICharacter& target);
        Ice    *clone() const;
};


#endif