#include "FragTrap.hpp"

FragTrap:: FragTrap(){
    this->name = "default";
    this->health = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "Create default FragTrap !" <<std::endl;  

}

FragTrap:: FragTrap(const FragTrap &assign) : ClapTrap(assign) {
    this->name = assign.name ;
    this->health = assign.health;
    this->energy = assign.energy;
    this->damage = assign.damage;
    std::cout << this->name << " Copy constractor called and create " << this->name << std::endl;  
}

FragTrap:: FragTrap(const std::string name){
    this->name = name;
    this->health = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << this->name << " Created !" << std::endl;
}

FragTrap:: ~FragTrap(){
    std::cout << this->name << " Destroyed !" << std::endl;  
}

FragTrap   FragTrap::operator=(const FragTrap &assign){
    this->name = assign.name;
    this->health = assign.health;
    this->energy = assign.energy;
    this->damage = assign.damage;
    std::cout << "Copy assignement operator called\n"; 
    return *this;
}

void    FragTrap::attack(const std::string& target){
    if (this->energy > 0 && this->health > 0){
        std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->damage  << " points of damage!" << std::endl; 
        this->energy--;
    }
} 

void    FragTrap::highFivesGuys( ){
        std::cout << this->name << " High fiiiive ! \n"; 
}