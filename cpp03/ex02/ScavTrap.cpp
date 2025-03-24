#include "ScavTrap.hpp"

ScavTrap:: ScavTrap(){
    this->name = "scav";
    this->hitPoints = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "scav : Create default !" << std::endl;  
}

ScavTrap:: ScavTrap(const ScavTrap &assign) : ClapTrap(assign) {
    std::cout << "scav : Copy constractor called and create " << this->name << std::endl;  
}

ScavTrap:: ScavTrap(const std::string name){
    this->name = name;
    this->hitPoints = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "scav : " <<  this->name << " Created !" << std::endl;
}

ScavTrap:: ~ScavTrap(){
    std::cout << "scav : " <<  this->name << " Destroyed !" << std::endl;  
}

ScavTrap&   ScavTrap::operator=(const ScavTrap &assign){
    if (this != &assign){
        this->name = assign.name;
        this->hitPoints = assign.hitPoints;
        this->energy = assign.energy;
        this->damage = assign.damage;
    }
        std::cout << "scav : Copy assignement operator called\n"; 
    return *this;
}

void    ScavTrap::attack(const std::string& target){
    if (this->energy > 0 && this->hitPoints > 0){
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->damage  << " points of damage!" << std::endl; 
        this->energy--;
    }
} 

void    ScavTrap::guardGate(){
    std::cout << this->name << " is now in Gate keeper mode\n"; 
}