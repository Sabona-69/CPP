#include <phonebook.hpp>
#include <iostream>

void	PhoneBook::set_contact(Contact new_contacts[8], int index)
{
	if (index > 7 || index < 0)
	{
		std::cout << "Invalid Index";
		return;
	}
	new_contacts[index].set_first_name();
	new_contacts[index].set_last_name();
	new_contacts[index].set_nickname();
	new_contacts[index].set_phone_number();
	new_contacts[index].set_darkest_secret();
}
