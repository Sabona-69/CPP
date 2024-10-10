#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

std::string get_input();

Contact *PhoneBook::get_contact() {
	return contacts;
}

int PhoneBook::get_count() {
	return count;
}

void	PhoneBook::set_contact()
{
	contacts[count % 8].set_first_name();
	contacts[count % 8].set_last_name();
	contacts[count % 8].set_nickname();
	contacts[count % 8].set_phone_number();
	contacts[count % 8].set_darkest_secret();
	count++;
}

std::string get_input(std::string print)
{
	std::string input;
	// std::getline(std::cin, input);
		std::cout << print << std::endl;
	while (!input.empty()){
		std::cout << "Input can't be empty !\n";
		// std::getline(std::cin, input);
	}
	return input;
}


void PhoneBook::get_contact_info() {
	std::string input;
	int 		i;

	// std::cout << "Enter index of contact :" << std::endl;
	input = get_input("Enter index of contact :");
	i = std::atoi(input.c_str());
	if (i < 1 || i > count){
		std::cout << "Invalid Index" << std::endl;
		return ;
	}
	std::cout << "First name : " << contacts[i - 1].get_first_name() << std::endl;
	std::cout << "Last name : " << contacts[i - 1].get_last_name() << std::endl;
	std::cout << "Nickname : " << contacts[i - 1].get_nickname() << std::endl;
	std::cout << "Phone number : " << contacts[i - 1].get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << contacts[i - 1].get_darkest_secret() << std::endl;
}

std::string get_string(std::string str)
{
	std::string check = str;

	if (check.length() > 10)
		check = check.substr(0, 9) + '.';
	return check;
}

void PhoneBook::get_table()
{
	// std::string(44, '=')
	int	breaker = get_count() + 1;

	if (breaker >= 8)
		breaker = 8;
	std::cout << "============================================" << std::endl;
	std::cout << std::setw(10) << std::right << "index" << "|";
	std::cout << std::setw(10) << std::right << "first name" << "|";
	std::cout << std::setw(10) << std::right << "last name" << "|";
	std::cout << std::setw(10) << std::right << "nickname" << "|";
	std::cout << "\n============================================\n";
	for (int i = 0; i < breaker - 1; i++){
		std::cout << std::setw(10) << std::right << i + 1 << "|";
		std::cout << std::setw(10) << std::right << get_string(contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << std::right << get_string(contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << std::right << get_string(contacts[i].get_nickname()) << "|";
		// std::endl;
		std::cout << "\n============================================" << std::endl;
	}
}