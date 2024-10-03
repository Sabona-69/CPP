#include "phonebook.hpp"
#include "contact.hpp"
#include <iostream>

int	main()
{
	std::string	input;
	PhoneBook	Book;
	// if (ac == 2)
	// {
		while (1)
		{
			std::getline(std::cin, input);
			if (input == "ADD")
			{
				Book.set_contact();
			}
			else if (input == "SEARCH")
			{
				Book.get_table();
				for (int i = 0; i < Book.get_count(); i++)
					Book.get_contact();
				Book.get_contact_info();
			}
			else if (input == "EXIT")
				return 0;
		}
	std:: cout << std:: endl;
	}