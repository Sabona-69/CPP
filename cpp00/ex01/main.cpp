#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

int	main()
{
	std::string	input;
	PhoneBook	Book;
	// if (ac == 2)
	// {
		while (1)
		{
			std::cout << "Insert command >: ";
			if (!std::getline(std::cin, input))
				break;
			if (input == "ADD")
				Book.set_contact();
			else if (input == "SEARCH")
			{
				Book.get_table();
				for (int i = 0; i < Book.get_count(); i++)
					Book.get_contact();
				Book.get_contact_info();
			}
			else if (input == "EXIT")
				return 0;
			else {
				std::cout << "Please Insert right command (ADD, SEARCH or EXIT)" << std::endl;
			}
		}
		std:: cout << std:: endl;
}