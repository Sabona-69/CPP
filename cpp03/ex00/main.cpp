#include "ClapTrap.hpp"


int main()
{
    ClapTrap a("user 1");

    a.attack("user 2");
    a.beRepaired(2);
    a.takeDamage(10);
    return 0;

}
