#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &assign);
        ScavTrap(const std::string name);
        ~ScavTrap();
        void        attack(const std::string& target);
        ScavTrap    operator=(const ScavTrap &assign);
        void        guardGate();
};