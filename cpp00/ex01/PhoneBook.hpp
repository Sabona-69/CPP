#ifndef PHONBOOK_HPP
# define PHONBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook{
	private:
		int		count = 0;
		Contact contacts[8];
	public:
		Contact *get_contact();
		int get_count();
		// std::string get_string(std::string str);
		void set_contact();
		void get_table();
		void get_contact_info();
};

#endif