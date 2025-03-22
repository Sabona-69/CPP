#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main()
{
    ScavTrap b("1");

    ClapTrap a("2");
    FragTrap c("3");
    a.attack("test");
    b.attack("allo");
    b.guardGate();
    c.highFivesGuys();
    return 0;
}
