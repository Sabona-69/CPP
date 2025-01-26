#ifndef HUMBNB_HPP
# define HUMBNB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB{
	private:
		std::string name;
		Weapon		weapon;	
	public:
		// HumanB();
		HumanB(const std::string &name);
		~HumanB();
		void	attack();
		void	setWeapon(const Weapon &weapon);
		
};




#endif