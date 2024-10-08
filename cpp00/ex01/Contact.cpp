#include "PhoneBook.hpp"
#include "Contact.hpp"

std::string Contact::get_first_name() {
	return first_name;
}	

std::string Contact::get_last_name() {
	return last_name;
};

std::string Contact::get_nickname() {
	return nickname;
};

std::string Contact::get_phone_number() {
	return phone_number;
};

std::string Contact::get_darkest_secret() {
	return darkest_secret;
};

void	Contact::set_first_name()
{
	std::cout << "First name : ";
	std::string new_fname;
	std::getline(std::cin, new_fname);
	first_name = new_fname;
}
void	Contact::set_last_name()
{
	std::string new_lname;
	std::cout << "Last name : ";
	std::getline(std::cin, new_lname);
	last_name = new_lname;
}
void	Contact::set_nickname()
{
	std::string new_nickname;
	std::cout << "Nickname : ";
	std::getline(std::cin, new_nickname);
	nickname = new_nickname;
}
void	Contact::set_phone_number()
{
	std::string new_number;
	std::cout << "Phone number : ";
	std::getline(std::cin, new_number);
	phone_number = new_number;
}
void	Contact::set_darkest_secret()
{
	std::string new_darkest_secret;
	std::cout << "Darkest secret : ";
	std::getline(std::cin, new_darkest_secret);
	darkest_secret = new_darkest_secret;
}



