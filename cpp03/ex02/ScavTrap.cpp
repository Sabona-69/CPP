#include "ScavTrap.hpp"

ScavTrap:: ScavTrap(){
    this->name = "default";
    this->health = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "Create default ScavTrap !" <<std::endl;  

}

ScavTrap:: ScavTrap(const ScavTrap &assign) : ClapTrap(assign) {
    this->name = assign.name ;
    this->health = assign.health;
    this->energy = assign.energy;
    this->damage = assign.damage;
    std::cout << this->name << " Copy constractor called and create " << this->name << std::endl;  
}

ScavTrap:: ScavTrap(const std::string name){
    this->name = name;
    this->health = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << this->name << " Created !" <<std::endl;
}

ScavTrap:: ~ScavTrap(){
    std::cout << this->name << " Destroyed !" <<std::endl;  
}

ScavTrap   ScavTrap::operator=(const ScavTrap &assign){
    this->name = assign.name;
    this->health = assign.health;
    this->energy = assign.energy;
    this->damage = assign.damage;
    std::cout << "Copy assignement operator called\n"; 
    return *this;
}

void    ScavTrap::attack(const std::string& target){
    if (this->energy > 0 && this->health > 0){
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage  << " points of damage!" << std::endl; 
        this->energy--;
    }
} 

void    ScavTrap::guardGate(){
    std::cout << this->name << " is now in Gate keeper mode\n"; 
}