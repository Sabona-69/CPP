#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap {
    public:
        ScavTrap();
        ScavTrap(const ScavTrap &assign);
        ScavTrap(const std::string name);
        ~ScavTrap();
        void        attack(const std::string& target);
        ScavTrap&    operator=(const ScavTrap &assign);
        void        guardGate();
};

#endif