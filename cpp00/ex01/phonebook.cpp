#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact *PhoneBook::get_contact() {
	return contacts;
}

int PhoneBook::get_count() {
	return count;
}

void	PhoneBook::set_contact()
{
	if (count == 8)
		count = 0;
	contacts[count].set_first_name();
	contacts[count].set_last_name();
	contacts[count].set_nickname();
	contacts[count].set_phone_number();
	contacts[count].set_darkest_secret();
	count++;
}

void PhoneBook::get_contact_info() {
	std::string input;
	int 		i;

	std::cout << "Enter index of contact :" << std::endl;
	std::getline(std::cin, input);
	i = std::stoi(input);
	if (i < 1 || i > count + 1){
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	std::cout << "First name : " << contacts[i - 1].get_first_name() << std::endl;
	std::cout << "Last name : " << contacts[i - 1].get_last_name() << std::endl;
	std::cout << "Nickname : " << contacts[i - 1].get_nickname() << std::endl;
	std::cout << "Phone number : " << contacts[i - 1].get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << contacts[i - 1].get_darkest_secret() << std::endl;
}

void PhoneBook::get_table()
{
	std::string(44, '=');
	std::cout << "|   index  |first_name|last_name | nickname |\n";// << std::endl;
	std::string(44, '=');
	for (int i = 0; i < get_count(); i++){
		std::cout << std::getw(10) << std::right << "|" << i + 1
				  << std::setw(10) << std::right << "|" << contacts[i].get_string(contacts[i].get_first_name())
				  << std::setw(10) << std::right << "|" << contacts[i].get_string(contacts[i].get_last_name())
				  << std::setw(10) << std::right << "|" << contacts[i].get_string(contacts[i].get_nickname())
				  << "|" << std::endl;
		std::cout << "=============================================" << std::endl;
	}
}