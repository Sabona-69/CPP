#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	BitcoinExchange btc;
	try {
		btc.validateProgramInputs(ac, av);
		btc.fillDataBase();
		btc.parseFile();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

}