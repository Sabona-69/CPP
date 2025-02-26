#include "ClapTrap.hpp"

ClapTrap:: ClapTrap(){
    this->name = "default";
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
    std::cout << "Create default ClapTrap !" <<std::endl;  

}
ClapTrap:: ClapTrap(const ClapTrap &assign){
    this->name = assign.name ;
    this->health = assign.health;
    this->energy = assign.energy;
    this->damage = assign.damage;
    std::cout << this->name << " Copy Constractor called and create " << this->name << std::endl;  
}


ClapTrap:: ClapTrap(const std::string name){
    this->name = name;
    this->health = 10;
    this->energy = 10;
    this->damage = 0;
    std::cout << this->name << " Created !" <<std::endl;
}

ClapTrap:: ~ClapTrap(){
    std::cout << this->name << " Destroyed !" <<std::endl;  
}

ClapTrap   ClapTrap::operator=(const ClapTrap &assign){
    this->name = assign.name;
    this->health = assign.health;
    this->energy = assign.energy;
    this->damage = assign.damage;
    return *this;
}

void ClapTrap::attack(const std::string& target){
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage  << "points of damage!" << std::endl;  
}

void ClapTrap::takeDamage(unsigned int amount){
    if (this->health != 0 && this->energy != 0 && amount > 0){
        this->health -= amount;
        this->energy -= 1;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->health != 0 && this->energy != 0 && amount > 0){
        this->health += amount;
        this->energy -= 1;
    }
}
