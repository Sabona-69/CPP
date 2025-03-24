#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    private:
        std::string     name;
        unsigned int    energy;
        unsigned int    hitPoints;
        unsigned int    damage;
    public:
        ClapTrap();
        ClapTrap(const ClapTrap &assign);
        ClapTrap(const std::string name);
        ~ClapTrap();
        ClapTrap&   operator=(const ClapTrap &assign);
        void        attack(const std::string& target);
        void        takeDamage(unsigned int amount);
        void        beRepaired(unsigned int amount);
};

#endif