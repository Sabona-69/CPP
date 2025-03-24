#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :  public FragTrap ,  public ScavTrap{
    private:
        std::string     name;
    public: 
        DiamondTrap();
        DiamondTrap(const DiamondTrap &assign);
        DiamondTrap(const std::string name);
        ~DiamondTrap();
        void            attack(const std::string& target);
        DiamondTrap&     operator=(const DiamondTrap &assign);
        void            WhoAmI();
};

#endif