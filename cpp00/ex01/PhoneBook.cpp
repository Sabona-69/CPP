#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

Contact *PhoneBook::get_contact() {
	return contacts;
}

int PhoneBook::get_count() {
	return count % 8;
}

void	PhoneBook::set_contact()
{
	// if (count == 8)
	// 	count = 0;
	std::cout << count;
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

std::string PhoneBook::get_string(std::string str)
{
	std::string check = str;

	if (check.length() > 10)
		check = check.substr(0, 9) + '.';
	return check;
}

void PhoneBook::get_table()
{
	// std::string(44, '=')

	std::cout << "==============================================" << std::endl;
	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "first name" << "|";
	std::cout << std::setw(10) << std::right << "last name" << "|";
	std::cout << std::setw(10) << std::right << "nickname";
	std::cout << "\n==============================================" << std::endl;
	// std::string(44, '=');
	for (int i = 0; i < get_count(); i++){
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		std::cout << std::setw(10) << std::right << get_string(contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << std::right << get_string(contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << std::right << get_string(contacts[i].get_nickname()) << "|";
		// std::endl;
		std::cout << "\n==============================================" << std::endl;
	}
}