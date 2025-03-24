#include "ClapTrap.hpp"

ClapTrap:: ClapTrap(){
    this->name = "clap";
    this->hitPoints = 10;
    this->energy = 10;
    this->damage = 0;
    std::cout << "Create default ClapTrap !" << std::endl;  

}
ClapTrap:: ClapTrap(const ClapTrap &assign){
    this->name = assign.name ;  
    this->hitPoints = assign.hitPoints;
    this->energy = assign.energy;
    this->damage = assign.damage;
    std::cout << "clap : Copy constractor called and create " << this->name << std::endl;  
}


ClapTrap:: ClapTrap(const std::string name){
    this->name = name;
    this->hitPoints = 10;
    this->energy = 10;
    this->damage = 0;
    std::cout <<  "clap : " << this->name << " Created !" << std::endl;
}

ClapTrap:: ~ClapTrap(){
    std::cout <<  "clap : " << this->name << " Destroyed !" << std::endl;  
}

ClapTrap&   ClapTrap::operator=(const ClapTrap &assign){
    if (this != &assign){
        this->name = assign.name;
        this->hitPoints = assign.hitPoints;
        this->energy = assign.energy;
        this->damage = assign.damage;
    }
    std::cout << "clap : Copy assignement operator called\n"; 
    return *this;
}

void ClapTrap::attack(const std::string& target){
    if (this->energy > 0 && this->hitPoints > 0){
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage  << " points of damage!" << std::endl; 
        this->energy--;
    }
    else
        std::cout << "ClapTrap " << name << " can't attack !" << std::endl;
} 

void ClapTrap::takeDamage(unsigned int amount) {
    if (hitPoints == 0) {
        std::cout << "ClapTrap " << name << " is already destroyed!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " took " << amount << " points of damage!" << std::endl;
    if (hitPoints < amount)
        hitPoints = 0;
    else
        hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (hitPoints > 0 && energy > 0) {
        hitPoints += amount;
        energy--;
        std::cout << "ClapTrap " << name << " healed " << amount << " points of hitPoints!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << name << " cannot be repaired!" << std::endl;
}