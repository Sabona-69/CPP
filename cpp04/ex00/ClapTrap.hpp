#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    protected:
        std::string     name;
        unsigned int    energy;
        unsigned int    hitPoints;
        unsigned int    damage;
    public:
    ClapTrap(const std::string name);
        ClapTrap();
        ~ClapTrap();
        
        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

#endif