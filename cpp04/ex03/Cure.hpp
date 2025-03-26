#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
    public:
        Cure();
        ~Cure();
        Cure(const Cure &assign);
        Cure&   operator=(const Cure &assign);
        void    use(ICharacter& target);
        Cure    *clone() const;
};


#endif