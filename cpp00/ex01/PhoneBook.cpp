#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() {
	this->count =  0;
}

PhoneBook::~PhoneBook(){
}

int PhoneBook::get_count() {
	return count;
}

void	PhoneBook::set_contact()
{
	Contact	temp;

	temp.set_first_name();
	if (temp.get_first_name().empty())
		return ;
	temp.set_last_name();
	if (temp.get_last_name().empty())
		return ;
	temp.set_nickname();
	if (temp.get_nickname().empty())
		return ;
	temp.set_phone_number();
	if (temp.get_phone_number().empty())
		return ;
	temp.set_darkest_secret();
	if (temp.get_darkest_secret().empty())
		return ;
	contacts[count % 8] = temp;
	count++;
}

std::string get_input(std::string prompt)
{
	std::string input;
	bool		isValid;

	while (true) {
		isValid = true;
        std::cout << prompt;
        if (!std::getline(std::cin, input))
			return std::string("");
		for (size_t i = 0; i < input.length(); i++) {
            if (!isprint((unsigned char)input[i])) {
                isValid = false;
                break;
            }
        }
        if (!input.empty() && isValid)
            break;
		std::cout << "Invalid Input !\n";
    }
    return input;
}

void PhoneBook::get_contact_info() {
	std::string input;
	int 		i = 0;;

	if (!count)
		return ;
	while (true){
		input = get_input("Enter index of contact :");
		i = input[0] - 48;
		if (input.length() != 1 || i < 1 || i > count)
			std::cout << "Invalid Index" << std::endl;
		else
			break;
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
	int	breaker = get_count();

	if (!count){
		std::cout << "The PhoneBook is empty ! try to add a new one\n";
		return ;
	}
	if (breaker > 8)
		breaker = 8;
	std::cout << "============================================\n";
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << "|";
	std::cout << "\n============================================\n";
	for (int i = 0; i < breaker; i++){
		std::cout << std::setw(10) << i + 1 << "|";
		std::cout << std::setw(10) << get_string(contacts[i].get_first_name()) << "|";
		std::cout << std::setw(10) << get_string(contacts[i].get_last_name()) << "|";
		std::cout << std::setw(10) << get_string(contacts[i].get_nickname()) << "|";
		std::cout << "\n============================================\n";
	}
}