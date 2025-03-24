#include "FragTrap.hpp"

int main() {
    FragTrap frag("Fraggy");

    frag.attack("Boss");
    frag.takeDamage(30);
    frag.beRepaired(20);
    frag.highFivesGuys();

    return 0;
}