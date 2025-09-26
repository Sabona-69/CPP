#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { }
BitcoinExchange::~BitcoinExchange() {
	if (file.is_open())
		file.close();
	if (dataBaseFile.is_open())
		dataBaseFile.close();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &assign) { }
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &assign){ return *this; }

void	BitcoinExchange::validateProgramInputs(int ac, char **av) {
	if (ac != 2)  throw std::runtime_error("Error: could not open file.");
	
	file.open(av[1]);
	dataBaseFile.open("data.csv");
	if (!file.is_open() || !dataBaseFile.is_open()) {
		throw std::runtime_error("Error: could not open file.");
	}
}

bool	isAllDegit(const std::string& str){
	for (size_t i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i]))
			return false;	
	}
	return true;	
}

std::string		strTrim(const std::string& str, const std::string& charset)
{
	size_t begin = str.find_first_not_of(charset);
	if (begin == std::string::npos)
		return ("");
	size_t end =  str.find_last_not_of(charset);
	return (str.substr(begin, end - begin + 1));
}
bool	validateDate(const std::string& date) {
	std::string	yearStr;
	std::string	monthStr;
	std::string	dayStr;
	yearStr = date.substr(0, 4);
	monthStr = date.substr(5, 2);
	dayStr = date.substr(8, 2);
	// validate degits
	if (isAllDegit(yearStr) == false || isAllDegit(monthStr) == false || isAllDegit(dayStr) == false)
		return false;
	int	year = (int)atol(yearStr.c_str());
	if (year == 0)
		return false;
	int	month = (int)atol(monthStr.c_str());
	if (month == 0 || month > 12)
		return false;
	int	day = (int)atol(dayStr.c_str());
	if (day == 0 || day > 31 || (month == 2 && day > 29))
		return false;
	// check for leap year
	if (month == 2 && day == 29) {
		if (!((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return false;
	}
	// check for months with 30 days
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}

bool	validateFormat(const std::string& line, int type) {
	//  YYYY-MM-DD sp | sp value ==> at least 14 character
	if (type == INPUT_DELIMETER && line.size() < 14) return false;
	if (type == CSV_DELIMETER && line.size() < 12) return false;
	// validate date parts
	if (line.at(4) != '-' && line.at(7) != '-') return false;
	// validate comma
	if (type == CSV_DELIMETER) {
		if (line.at(10) != ',')  return false;
	}
	// validate sp + pipe + sp
	if (type == INPUT_DELIMETER) {
		if (line.at(10) != ' ' && line.at(11) != '|' && line.at(12) != ' ') return false;
	}
	return true;
}


float	extractValue(const std::string& valueStr) {
	float value;
	std::stringstream  ss(valueStr);

	ss >> value;
	if (ss.fail() || !ss.eof())
		return -42;
	return value;
}


bool	BitcoinExchange::validateLine(const std::string& line){
	// validate format
	if (validateFormat(line, INPUT_DELIMETER) == false) {
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}
	if (validateDate(line.substr(0, 10)) == false) {
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}
	float value = extractValue(line.substr(13));
	if (value < 0 || value > 1000) {
		if (value == -42)
			std::cout << "Error: bad input => " << line << std::endl;
		else if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else
			std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

void	BitcoinExchange::calculatedAndPrintValue(const std::string& line) {
	std::string	date = line.substr(0, 10);
	float			value = extractValue(line.substr(13));

	dataBaseMap::iterator it = dataBase.find(date);
	if (it == dataBase.end()) {
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
	else {
		it = dataBase.lower_bound(date);
		if (it != dataBase.begin())
			--it;
		std::cout << date << " => " << value << " = " << value * it->second << std::endl;
	}
}

void	BitcoinExchange::parseFile() {
	std::string	line;
	std::getline(file, line);
	while (!file.eof()) {
		std::getline(file, line);
		line = strTrim(line, " \t");
		if (!line.empty()) {
			if (line != "date | value")
				file.seekg(((line.size() + 1) * -1) , std::ios::cur);
			break;
		}
	}
	while (!file.eof()) {
		std::getline(file, line);
		line = strTrim(line, " \t");
		if (line.empty()) continue ;
		if (validateLine(line) == false) continue ;
		calculatedAndPrintValue(line);
	}
}

void BitcoinExchange::fillDataBase() {
	std::string	line;
	std::string	date;
	std::string	value;
	// skip header
	while (!dataBaseFile.eof()) {
		std::getline(dataBaseFile, line);
		line = strTrim(line, " \t");
		if (!line.empty()){
			if (line != "date,exchange_rate")
				dataBaseFile.seekg((line.size() + 1) * -1 , std::ios::cur);
			break;
		}
	}
	while (!dataBaseFile.eof()) {
		std::getline(dataBaseFile, line);
		line = strTrim(line, " \t");
		if (line.empty()) continue;
		// validate format
		if (validateFormat(line, CSV_DELIMETER) == false)
			throw std::runtime_error("Error: Invalid database format !");
		date = line.substr(0, 10);
		value = line.substr(11);
		// validate date
		if (validateDate(date) == false)
			throw std::runtime_error("Error: Invalid database date !");
		// validate value
		float val = extractValue(value);
		if (val == -1)
			throw std::runtime_error("Error: Invalid database value !");
		dataBase.insert(std::make_pair(date , val));
	}
}


