#ifndef PHONBOOK_HPP
# define PHONBOOK_HPP

#include <contact.hpp>

class PhoneBook{
	private:
		int		count = 0;
		Contact contacts[8];
	public:
		void set_contact(Contact new_contacts[8], int index);
		void get_contact(Contact new_contacts[8], int index);
		

};

#endif