#ifndef PHONBOOK_HPP
# define PHONBOOK_HPP

#include <iostream>
#include "contact.hpp"

class PhoneBook{
	private:
		int		count;
		Contact contacts[8];
	public:
		Contact *get_contact(){
			return contacts;
		}
		int get_count(){
			return count;
		}
		void set_contact();
		void get_table();
		void get_contact_info();
		// void 

};

#endif