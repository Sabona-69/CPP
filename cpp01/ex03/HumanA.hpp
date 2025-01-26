#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA{
	private:
		std::string name;
		Weapon		*weapon;
	public:
		// HumanA();
		HumanA(const std::string &name, const Weapon &weapon);
		~HumanA();
		void	attack();
		void	setWeapon(const Weapon &weapon);
		
};




#endif