#include "FragTrap.hpp"

FragTrap:: FragTrap(){
    this->name = "frag";
    this->hitPoints = 100;
    if (energy != 50)
        this->energy = 100;
    this->damage = 30;
    std::cout << "frag : Create default !" << std::endl;  

}

FragTrap:: FragTrap(const FragTrap &assign) : ClapTrap(assign) {
    std::cout << "frag : Copy constractor called and create " << this->name << std::endl;  
}

FragTrap:: FragTrap(const std::string name){
    this->name = name;
    this->hitPoints = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "frag : " << this->name << " Created !" << std::endl;
}

FragTrap:: ~FragTrap(){
    std::cout << "frag : " << this->name << " Destroyed !" << std::endl;  
}

FragTrap&   FragTrap::operator=(const FragTrap &assign){
    if (this != &assign){
    this->name = assign.name;
    this->hitPoints = assign.hitPoints;
    this->energy = assign.energy;
    this->damage = assign.damage;
    }
    std::cout << "frag : Copy assignement operator called\n"; 
    return *this;
}

void    FragTrap::highFivesGuys( ){
        std::cout << this->name << " High fiiiive ! \n"; 
}