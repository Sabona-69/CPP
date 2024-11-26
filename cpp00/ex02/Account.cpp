/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-omra <hel-omra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:44:43 by hel-omra          #+#    #+#             */
/*   Updated: 2024/11/08 06:53:52 by hel-omra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

Account::Account( int initial_deposit ){
	_amount = initial_deposit;
}

Account::~Account(){

}

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

void	Account::displayAccountsInfos( void ){
	// accounts:8;total:20049;deposits:0;withdrawals:
	std::cout << "account:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits" << getNbDeposits() << ";"	;
	std::cout << "withdrawals:" << getNbWithdrawals() << ";";
	// return _totalNbDeposits;
}

void Account::makeDeposit( int deposit ){
	_nbDeposits++;
	_amount += deposit;		
}

bool Account::makeWithdrawal( int withdrawal ){
	_nbWithdrawals++;
	_amount -= withdrawal;
	return 1;
}

int	const	Account::checkAmount(){

};
	
}