#include <iostream>

int main(){
	std::string str = "HI THIS IS BRAIN.";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "this is address of str = " << &str << std::endl;
	std::cout << "this is address helds by stringPTR = " << stringPTR << std::endl;
	std::cout << "this is address helds by  stringREF = " << &stringREF << std::endl;
	std::cout << std::string(52, '=') << std::endl;
	std::cout << "this is the value of the string str = " << str << std::endl;
	std::cout << "this is the value pointed by stringPTR = " << *stringPTR << std::endl;
	std::cout << "this is the value pointed by stringREF = " << stringREF << std::endl;
}