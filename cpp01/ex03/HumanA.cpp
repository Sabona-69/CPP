#include "HumanA.hpp"

void	HumanA::attack(){
	std::cout << this->name  << " attacks with their " << this->weapon.get_Type();
}

void	HumanA::setWeapon(const Weapon &weapon){
	this->weapon = weapon;
}

HumanA::HumanA(const std::string &name, const Weapon &weapon){
	
	this->name = name;
}

HumanA::~HumanA()
{
}