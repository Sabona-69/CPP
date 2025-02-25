#include "ClapTrap.hpp"

ClapTrap:: ClapTrap(){
    // this->name = "";
}

ClapTrap:: ClapTrap(const ClapTrap &assign){
    
}

ClapTrap:: ClapTrap(const std::string name){
    this->name = name;
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
}

ClapTrap:: ~ClapTrap(){

}

// ClapTrap   ClapTrap::operator=(const ClapTrap &assign){

// }

void ClapTrap::attack(const std::string& target){
    
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->health != 0 && this->energy != 0 && amount > 0){
        this->health -= amount;
        this->energy -= 1;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->health != 0 && this->energy != 0){
        this->health += amount;
        this->energy -= 1;
    }
}
