#include "DiamondTrap.hpp"

int main() {
    DiamondTrap diamond("Diamy");

    diamond.attack("FinalBoss");
    diamond.takeDamage(50);
    diamond.beRepaired(30);
    diamond.WhoAmI();
    return 0;
}