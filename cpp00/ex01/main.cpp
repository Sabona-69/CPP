#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	std::string	input;
	PhoneBook	Book;
	while (true)
	{
		std::cout << "Insert command >: ";
		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD")
			Book.set_contact();
		else if (input == "SEARCH")
		{
			Book.get_table();
			Book.get_contact_info();
		}
		else if (input == "EXIT")
			return 0;
		else {
			std::cout << "Please Insert right command (ADD, SEARCH or EXIT)" << std::endl;
		}
	}	
}
