#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
    std::cout << "Default BitcoinExchange Constructor called !" << std::endl;
}

BitcoinExchange::~BitcoinExchange(){
    std::cout << "Default BitcoinExchange Destructor called !" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &assign){
    std::cout << "BitcoinExchange Copy Constructor called !" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &assign){
    if (this != &assign){
        // Assignment logic here
    }
    return *this;
}

void	BitcoinExchange::validateProgramInputs(int ac, char **av) {

	if (ac != 2) {
		throw std::runtime_error("Invalid arguments !");
	}
	file.open(av[1]);
	dataBaseFile.open("database.csv");

	if (!file.is_open() || !dataBaseFile.is_open()) {
		throw std::runtime_error("cant open file !");
	}
}

bool	isStrDegit(const std::string& str){
	for (size_t i = 0; i < str.size(); ++i) {
		if (!isdigit(str[i]))
			return false;	
	}
	return true;	
}

std::string		strTrin(const std::string& str, const std::string& charset)
{
	size_t begin = str.find_first_not_of(charset);
	size_t end =  str.find_last_not_of(charset);
	return (str.substr(begin, end));

}
bool	validateDate(const std::string& date) {
	std::string	yearStr;
	std::string	monthStr;
	std::string	dayStr;

	if (date.size() < 10)
		return false;

	// validate seperators
	if (date.at(4) != '-' && date.at(7) != '-')
		return false;

	yearStr = date.substr(0, 4);
	monthStr = date.substr(5, 2);
	dayStr = date.substr(8, 2);

	// validate degits
	if (isStrDegit(yearStr) == false || isStrDegit(monthStr) == false || isStrDegit(dayStr) == false)
		return false;

	int	year = (int)atol(yearStr.c_str());
	if (year < 2008)
		return false;

	int	month = (int)atol(monthStr.c_str());
	if (month == 0 || month > 12)
		return false;

	int	day = (int)atol(dayStr.c_str());
	if (day == 0 || day > 31)
		return false;
	
	// special date
	if (year == 2008  && (month < 11 || (month == 11 && day < 18)))
		return false;
	return true;
}

void	BitcoinExchange::validateLine(const std::string& line){

	// validate date  <date = YYYY-MM-DD sp | sp value>
	size_t safeSize = 18; //  YYYY-MM-DD sp | sp value ==> at least 18 character
	if (line.size() < safeSize)
		std::cout << "bad input => " << line << std::endl;
	

}
void	BitcoinExchange::parseFile() {
	std::string	line;

	std::getline(file, line);
	if (line != "date | value")
		file.seekg(0 , std::ios::beg);
	while (!file.eof())
	{
		std::getline(file, line);
		line = strTrin(line, " \t");
		if (line.empty())
			throw std::runtime_error("Empty line !");
		validateLine(line);
	}
}

void BitcoinExchange::fillDataBase() {
	std::string	line;
	std::string	date;
	std::string	value;
	
	std::getline(dataBaseFile, line);
	while (!dataBaseFile.eof())
	{
		size_t pos = line.find(",");
		date = line.substr(0, pos);
		value = line.substr(pos + 1);
		dataBase.insert(std::make_pair(date , atof(value.c_str())));
	}

}