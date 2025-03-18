#include "Scavtrap.hpp"

Scavtrap:: Scavtrap(){
    this->name = "default";
    this->health = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << "Create default Scavtrap !" <<std::endl;  

}
Scavtrap:: Scavtrap(const Scavtrap &assign){
    this->name = assign.name ;
    this->health = assign.health;
    this->energy = assign.energy;
    this->damage = assign.damage;
    std::cout << this->name << " Copy constractor called and create " << this->name << std::endl;  
}

Scavtrap:: Scavtrap(const std::string name){
    this->name = name;
    this->health = 100;
    this->energy = 50;
    this->damage = 20;
    std::cout << this->name << " Created !" <<std::endl;
}

Scavtrap:: ~Scavtrap(){
    std::cout << this->name << " Destroyed !" <<std::endl;  
}

Scavtrap   Scavtrap::operator=(const Scavtrap &assign){
    this->name = assign.name;
    this->health = assign.health;
    this->energy = assign.energy;
    this->damage = assign.damage;
    std::cout << "Copy assignement operator called\n"; 
    return *this;
}

void Scavtrap::attack(const std::string& target){
    if (this->energy > 0 && this->health > 0){
        std::cout << "Scavtrap " << this->name << " attacks " << target << ", causing " << this->damage  << " points of damage!" << std::endl; 
        this->energy--;
    }
} 
