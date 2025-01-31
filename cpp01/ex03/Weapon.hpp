#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
	private:
		std::string str;
	public:
	Weapon(const std::string &weapon);
	const std::string getType() const;
	void	setType(const std::string &str);
};

#endif