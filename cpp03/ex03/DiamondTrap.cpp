#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
    ClapTrap::name = "diam_clap_name";
    this->name = "diam";
    this->hitPoints = FragTrap::hitPoints;
    this->energy = ScavTrap::energy;
    this->damage = FragTrap::damage;
    std::cout << "Create default DiamondTrap!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &assign) : ClapTrap(assign.name + "_clap_name"), FragTrap() , ScavTrap(){
    std::cout <<"diam : Copy constractor called and create " << this->name << std::endl;  
}

DiamondTrap:: DiamondTrap(const std::string name){
    ClapTrap::name = name + "_clap_name";
    this->name = name;
    this->hitPoints = FragTrap::hitPoints; 
    this->energy = ScavTrap::energy;  
    this->damage = FragTrap::damage; 
    std::cout << "diam : " << this->name << " Created !" << std::endl;
}

DiamondTrap:: ~DiamondTrap(){
    std::cout << "The " << ClapTrap::name << " who has " << this->name << " Destroyed in diamondtrap !" << std::endl;  
}

DiamondTrap&   DiamondTrap::operator=(const DiamondTrap &assign){
    if (this != &assign){
        ClapTrap::name = assign.name + "_clap_name";
        this->name = assign.name;
        this->hitPoints = assign.hitPoints;
        this->energy = assign.energy;
        this->damage = assign.damage;
    }
    std::cout << "diam : Copy assignement operator called\n"; 
    return *this;
}

void    DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);    
} 

void    DiamondTrap::WhoAmI(){
    std::cout << "I am " << this->name << " and my ClapTrap name is " << ClapTrap::name << std::endl;
}