#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class AMateria;

class Character : public ICharacter {
    private:
        std::string name;
        AMateria* inventory[4];
        AMateria* garbage[4];
    public:
        Character();
        Character(const Character &assign);
        Character(const std::string &assign);
        Character&   operator=(const Character &assign);
        ~Character();
        std::string const &getName() const;
        void    equip(AMateria* m);
        void    unequip(int idx);
        void    use(int idx, ICharacter& target);
};

#endif