#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {
    public:
        Character();
        Character(const Character &assign);
        Character&   operator=(const Character &assign);
        ~Character();
};


#endif