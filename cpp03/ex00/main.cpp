#include "ClapTrap.hpp"

int main() {
    ClapTrap a("RobotA");
    ClapTrap b("RobotB");

    a.attack("Target1");
    b.takeDamage(5);
    b.beRepaired(3);
    b.attack("Target2");

    return 0;
}
