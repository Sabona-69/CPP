#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

void testCharacter() {
    std::cout << "\n===== Testing Character =====" << std::endl;
    
    Character hero("Hero");
    AMateria* ice = new Ice();
    AMateria* cure = new Cure();
    AMateria* ice1 = new Ice();

    // Test equip()
    hero.equip(ice);      // Slot 0: Ice
    hero.equip(cure);     // Slot 1: Cure
    hero.equip(NULL);  // Should skip (no crash)
    hero.equip(new Ice()); // Slot 2: Ice
    hero.equip(new Cure()); // Slot 3: Cure
    hero.equip(ice1);  // Inventory full (ignored)
    delete ice1;
    // Test use()
    Character enemy("Enemy");
    hero.use(0, enemy);  // * shoots ice bolt at Enemy *
    hero.use(1, enemy);  // * heals Enemy's wounds *
    hero.use(3, enemy);  // * heals Enemy's wounds *
    hero.use(99, enemy); // Invalid index (no crash)
    
    // Test unequip() - we'll track the pointer another way
    AMateria* tmpCure = new Cure();  // Create new materia to track
    hero.equip(tmpCure);             // Add to inventory (slot 1 if empty)
    hero.unequip(1);                 // Remove from inventory (doesn't delete)
    // Now tmpCure still exists and must be manually deleted
    delete tmpCure;
    
    // Test copy constructor (deep copy)
    Character clone(hero);
    clone.use(0, enemy); // Should work with copied materia
}

void testMateriaSource() {
    std::cout << "\n===== Testing MateriaSource =====" << std::endl;
    
    MateriaSource src;
    src.learnMateria(new Ice());  // Learn Ice (slot 0)
    src.learnMateria(new Cure()); // Learn Cure (slot 1)
    src.learnMateria(NULL);    // Should skip

    // Test createMateria()
    AMateria* ice = src.createMateria("ice");
    AMateria* cure = src.createMateria("cure");
    AMateria* unknown = src.createMateria("fire"); // NULL

    Character bob("Bob");
    if (ice) {
        bob.equip(ice);
        ice = NULL; // Now owned by bob
    }
    if (cure) {
        bob.equip(cure);
        cure = NULL; // Now owned by bob
    }
    
    Character target("Target");
    bob.use(0, target); // * shoots ice bolt at Target *
    delete unknown; // Safe (NULL)
}

int main() {
    std::cout << "===== Starting Tests =====" << std::endl;
    
    testCharacter();
    testMateriaSource();
    //     IMateriaSource* src = new MateriaSource();
    //     src->learnMateria(new Ice());
    //     src->learnMateria(new Cure());
    //     ICharacter* me = new Character("me");
    //     AMateria* tmp;
    //     tmp = src->createMateria("ice");
    //     me->equip(tmp);
    //     tmp = src->createMateria("cure");
    //     me->equip(tmp);
    //     ICharacter* bob = new Character("bob");
    //     me->use(0, *bob);
    //     me->use(1, *bob);
    //     delete bob;
    //     delete me;
    //     delete src;

    std::cout << "\n===== Tests Complete =====" << std::endl;
    return 0;
}
