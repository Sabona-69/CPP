#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
	private:
		std::string str;
	public:
	std::string const &get_Type();
	void	const &set_Type(std::string &str);
};

#endif