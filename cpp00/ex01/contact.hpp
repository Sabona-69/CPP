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
		void set_first_name();
		void set_last_name();
		void set_nickname();
		void set_phone_number();
		void set_darkest_secret();
		void get_contact_info();
};

#endif