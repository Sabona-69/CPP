#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>

typedef std::map<std::string, float> dataBaseMap;

class BitcoinExchange {
	private:
		dataBaseMap		dataBase;
		std::ifstream 	file;
		std::ifstream 	dataBaseFile;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &assign);
        BitcoinExchange& operator=(const BitcoinExchange &assign);

		void	validateProgramInputs(int ac, char **av);
		void	fillDataBase();
		void	validateLine(const std::string& line);
		void	parseFile();
};


#endif
