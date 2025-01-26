#include "Weapon.hpp"

const std::string Weapon::get_Type() const{
	return this->str;
}

void	Weapon::set_Type(const std::string &str){
	this->str = str;
}
