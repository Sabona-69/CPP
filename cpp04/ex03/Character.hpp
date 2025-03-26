#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter {
    private:
        std::string name;
        AMateria* inventory[4];
    public:
        Character();
        Character(const Character &assign);
        Character(const std::string &assign);
        Character&   operator=(const Character &assign);
        ~Character();
};


#endif