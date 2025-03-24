#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
    public:
    FragTrap();
    FragTrap(const FragTrap &assign);
    FragTrap(const std::string name);
    ~FragTrap();
    FragTrap&    operator=(const FragTrap &assign);
    void highFivesGuys(void);
};
#endif