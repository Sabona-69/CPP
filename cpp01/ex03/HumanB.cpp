#include "HumanB.hpp"

void	HumanB::attack(){
	std::cout << this->name  << " attacks with their " << this->weapon.get_Type();
}

void	HumanB::setWeapon(const Weapon &weapon){
	this->weapon = weapon;
}

HumanB::HumanB(const std::string &name){
	this->name = name;
}

HumanB::~HumanB()
{
}