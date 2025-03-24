#include "ScavTrap.hpp"

int main() {
    ScavTrap scav("Scavvy");

    scav.attack("Enemy1");
    scav.takeDamage(20);
    scav.beRepaired(10);
    scav.guardGate();

    return 0;
}