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
    std::cout << this->name << " Copy constractor called and create " << this->name << std::endl;  
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
    std::cout << "Copy assignement operator called\n"; 
    return *this;
}

void ClapTrap::attack(const std::string& target){
    if (this->energy > 0){
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage  << " points of damage!" << std::endl; 
        this->energy--;
    }
}

void ClapTrap::takeDamage(unsigned int amount){
    int     check = this->health - amount;
    if (check > -1 && this->energy > 0 && amount > 0){
        std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage!" << std::endl; 
        this->health = check;
        this->energy -= 1;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (this->health != 0 && this->energy != 0 && amount > 0){
        this->health += amount;
        this->energy -= 1;
        std::cout << "ClapTrap " << this->name << " healed " << amount << " points of health !" << std::endl; 
    }
}
