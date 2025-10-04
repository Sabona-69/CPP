#ifndef PHONBOOK_HPP
# define PHONBOOK_HPP

#include "Contact.hpp"
#include <iostream>


class PhoneBook{
	private:
		int		count;
		Contact contacts[8];
	public:
		PhoneBook();
		~PhoneBook();
		int get_count();
		void set_contact();
		void get_table();
		void get_contact_info();
};

#endif