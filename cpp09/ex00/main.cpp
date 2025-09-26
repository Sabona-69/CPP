#include "BitcoinExchange.hpp"

void printMap(const dataBaseMap& db) {
	for (dataBaseMap::const_iterator it = db.begin(); it != db.end(); ++it) {
		if (it->second == -42)
			return ;
		std::cout << it->first << "," << std::fixed << it->second << std::setprecision(2)  << std::endl;
	}
}

int main (int ac, char **av)
{
	BitcoinExchange btc;
	try {
		btc.validateProgramInputs(ac, av);
		btc.fillDataBase();
		// printMap(btc.dataBase);
		btc.parseFile();

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}

}