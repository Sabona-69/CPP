#ifndef PHONBOOK_HPP
# define PHONBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook{
	private:
		int		count;
		Contact contacts[8];
	public:
		Contact *get_contact();
		int get_count();
		void set_contact();
		void get_table();
		void get_contact_info();
};

#endif