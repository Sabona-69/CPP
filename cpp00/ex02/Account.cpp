/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:43 by hel-omra          #+#    #+#             */
/*   Updated: 2025/01/10 15:20:15 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account:: _totalAmount = 0;
int Account:: _totalNbWithdrawals = 0;
int Account:: _totalNbDeposits = 0;
int Account:: _nbAccounts = 0;

int Account:: getNbAccounts( void ){
	return _nbAccounts;
}

int Account:: getTotalAmount( void ){
	return _totalAmount;
}

int Account:: getNbDeposits( void ){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
}

int	Account::checkAmount()	const{
	return _amount;
};

void	Account::_displayTimestamp(){
	char timeStr[20];
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);
	std::strftime(timeStr, sizeof(timeStr), "[%Y%m%d_%H%M%S] ", ltm);
	std::cout << timeStr;
};

Account::Account( int initial_deposit ){
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbAccounts++;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account(){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayStatus( void ) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
};

void	Account::displayAccountsInfos( void ){
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";"	;
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::makeDeposit( int deposit ){
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_amount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount - deposit << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal > _amount){
		std::cout << "refused" << std::endl;
		return false;
	}
	_nbWithdrawals++;
	std::cout << withdrawal << ";amount:" << _amount - withdrawal << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}
