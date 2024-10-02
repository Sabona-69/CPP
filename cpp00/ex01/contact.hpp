#ifndef CONTACT_HPP
# define CONTACT_HPP

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
			{
				check[10] = '.';
				check[11] = '\0';
			}
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
		void set_first_name();
		void set_last_name();
		void set_nickname();
		void set_phone_number();
		void set_darkest_secret();
		void get_contact_info(int index);
};

#endif