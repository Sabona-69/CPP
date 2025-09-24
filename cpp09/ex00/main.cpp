#include <iostream>
#include <fstream>

int main (int ac, char **av)
{
	if (ac != 2) {
		std::cout << "Invalid arguments !\n";
		return 1;
	}
	std::ifstream file;
	
	file.open(av[1]);
	if (!file.is_open()) {
		std::cout << "cant open file !\n";
		return 1;
	}


}