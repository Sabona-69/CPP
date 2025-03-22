#pragma once

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap {
    public:
        FragTrap();
        FragTrap(const FragTrap &assign);
        FragTrap(const std::string name);
        ~FragTrap();
        void        attack(const std::string& target);
        FragTrap    operator=(const FragTrap &assign);
        void highFivesGuys(void);
};