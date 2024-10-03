#include "contact.hpp"
#include "phonebook.hpp"


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

void PhoneBook::get_contact_info(){
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
	std::cout << "=============================================" << std::endl;
	std::cout << "|   index  |first_name|last_name | nickname |" << std::endl;
	std::cout << "=============================================" << std::endl;
	for (int i = 0; i < get_count(); i++){
		std::cout << "|" << i + 1
				  << "|" << contacts[i].get_string(contacts[i].get_first_name())
				  << "|" << contacts[i].get_string(contacts[i].get_last_name())
				  << "|" << contacts[i].get_string(contacts[i].get_nickname())
				  << "|" << std::endl;
		std::cout << "=============================================" << std::endl;
	}
}