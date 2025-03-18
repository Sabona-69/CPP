#pragma once 

#include <iostream>

class ClapTrap{
    protected:
        std::string name;
        int         energy;
        int         health;
        int         damage;
    public:
    ClapTrap();
    ClapTrap(const ClapTrap &assign);
    ClapTrap(const std::string name);
    ~ClapTrap();
    virtual void    attack(const std::string& target);
    ClapTrap        operator=(const ClapTrap &assign);
    void            takeDamage(unsigned int amount);
    void            beRepaired(unsigned int amount);

};