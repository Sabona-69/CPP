#pragma once 

#include <iostream>

class ClapTrap{
    private:
        std::string name;
        int         energy;
        int         health;
        int         damage;
    public:
    ClapTrap();
    ClapTrap(const ClapTrap &assign);
    ClapTrap(const std::string name);
    ~ClapTrap();
    ClapTrap    operator=(const ClapTrap &assign);
    void        attack(const std::string& target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);

};