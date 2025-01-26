#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon{
	private:
		std::string str;
	public:
	const std::string get_Type() const;
	void	set_Type(const std::string &str);
};

#endif