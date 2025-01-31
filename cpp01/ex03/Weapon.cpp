#include "Weapon.hpp"

Weapon::Weapon(const std::string &weapon){
	this->str = weapon;
}

const std::string Weapon::getType() const{
	return this->str;
}

void	Weapon::setType(const std::string &str){
	this->str = str;
}
