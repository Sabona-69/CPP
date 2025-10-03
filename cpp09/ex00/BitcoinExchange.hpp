#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>

#define CSV_DELIMETER 1
#define INPUT_DELIMETER 2

typedef std::map<std::string, float> dataBaseMap;

class BitcoinExchange {
	private:
		std::ifstream 	file;
		std::ifstream 	dataBaseFile;
		dataBaseMap		dataBase;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &assign);
        BitcoinExchange& operator=(const BitcoinExchange &assign);

		void	validateProgramInputs(int ac, char **av);
		void	fillDataBase();
		bool	validateLine(const std::string& line);
		void	parseFile();
		void	calculatedAndPrintValue(const std::string& line);
};


#endif
