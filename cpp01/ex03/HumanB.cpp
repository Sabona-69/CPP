#include "HumanB.hpp"

HumanB::HumanB(const std::string &name){
	this->name = name;
	this->weapon = NULL;

}

void	HumanB::attack(){
	if (this->weapon)
		std::cout << this->name  << " attacks with their " <<  this->weapon->getType() << std::endl;
	else
		std::cout << this->name  << " has no weapon T-T " << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon){
	this->weapon = &weapon;
}

