#include "ClapTrap.hpp"
#include "ScavTrap.hpp"


int main()
{
    ScavTrap b("1");

    ScavTrap a(b);
    a.attack("test");
    b.attack("allo");
    b.guardGate();
    return 0;

}
