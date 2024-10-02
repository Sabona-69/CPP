#include <contact.hpp>
#include <iostream>

void	Contact::get_contact_info(Contact new_contact)
{
	std::string check = new_contact.first_name;
	if (check.length() > 10)
		check[9] = '.';
	
	std::cout << "|" <<  
}

void	Contact::set_first_name()
{
	std::cout << "First name : ";
	std::string new_fname;
	std::getline(std::cin, new_fname);
	std::cout << std::endl;
	first_name = new_fname;
}
void	Contact::set_last_name()
{
	std::string new_lname;
	std::cout << "Last name : ";
	std::getline(std::cin, new_lname);
	std::cout << std::endl;
	last_name = new_lname;
}
void	Contact::set_nickname()
{
	std::string new_nickname;
	std::cout << "Nickname : ";
	std::getline(std::cin, new_nickname);
	std::cout << std::endl;
	nickname = new_nickname;
}
void	Contact::set_phone_number()
{
	std::string new_number;
	std::cout << "Phone number : ";
	std::getline(std::cin, new_number);
	std::cout << std::endl;
	phone_number = new_number;
}
void	Contact::set_darkest_secret()
{
	std::string new_darkest_secret;
	std::cout << "Darkest secret : ";
	std::getline(std::cin, new_darkest_secret);
	std::cout << std::endl;
	darkest_secret = new_darkest_secret;
}