#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>

class Contact{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		std::string get_string(std::string str)
		{
			std::string check = str;

			if (check.length() > 10)
				check = check.substr(0, 9) + '.';
			return check;
		}
		std::string get_first_name(){
			return first_name;
		}	
		std::string get_last_name(){
			return last_name;
		};
		std::string get_nickname(){
			return nickname;
		};
		std::string get_phone_number(){
			return phone_number;
		};
		std::string get_darkest_secret(){
			return darkest_secret;
		};
		void set_first_name();
		void set_last_name();
		void set_nickname();
		void set_phone_number();
		void set_darkest_secret();
		// void print_contact(){
		// 	std::cout << first_name
		// };
};

#endif