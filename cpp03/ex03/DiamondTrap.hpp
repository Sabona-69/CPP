#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :  public FragTrap ,  public ScavTrap{
    private:
        std::string     _name;
    public: 
        DiamondTrap();
        DiamondTrap(const DiamondTrap &assign);
        DiamondTrap(const std::string name);
        ~DiamondTrap();
        void            attack(const std::string& target);
        DiamondTrap     operator=(const DiamondTrap &assign);
        void            WhoAmI();
};
