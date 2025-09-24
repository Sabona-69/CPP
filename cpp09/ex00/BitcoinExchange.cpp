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
