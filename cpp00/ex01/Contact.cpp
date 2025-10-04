#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact(){
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
}

Contact::~Contact(){
}

std::string get_input(std::string print);

std::string Contact::get_first_name() {
	return first_name;
}	

std::string Contact::get_last_name() {
	return last_name;
}

std::string Contact::get_nickname() {
	return nickname;
}

std::string Contact::get_phone_number() {
	return phone_number;
}

std::string Contact::get_darkest_secret() {
	return darkest_secret;
}

void	Contact::set_first_name()
{
	first_name = get_input("First name : ");
}
void	Contact::set_last_name()
{
	last_name = get_input("Last name : ");
}
void	Contact::set_nickname()
{
	nickname = get_input("Nickname : ");
}
void	Contact::set_phone_number()
{
	while (true)
	{
		bool checker = true;
		phone_number = get_input("Phone number : ");
		if (phone_number.length() > 10)
		{
			std::cout << "Invalid number !\n";
			checker = false;
		}
		else
			for (int i = 0; i < (int)phone_number.length(); i++)
			{
				if (!isdigit(phone_number[i])){
					std::cout << "The input must be numbers !\n";
					checker = false;
					break;
				}
			}
		if (checker)
			return;	
	}	
}

void	Contact::set_darkest_secret()
{
	darkest_secret = get_input("Darkest secret : ");
}
