/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:45:35 by licohen           #+#    #+#             */
/*   Updated: 2025/06/26 18:32:07 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0; 

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}

Account::~Account(void) 
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";deposits:" << _nbDeposits
	          << ";withdrawals:" << _nbWithdrawals
	          << std::endl;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
	          << ";total:" << getTotalAmount()
	          << ";deposits:" << getNbDeposits()
	          << ";withdrawals:" << getNbWithdrawals()
	          << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	struct tm *t = std::localtime(&now);

	std::cout << "["
	          << (t->tm_year + 1900)
	          << (t->tm_mon + 1 < 10 ? "0" : "") << (t->tm_mon + 1)
	          << (t->tm_mday < 10 ? "0" : "") << t->tm_mday
	          << "_"
	          << (t->tm_hour < 10 ? "0" : "") << t->tm_hour
	          << (t->tm_min < 10 ? "0" : "") << t->tm_min
	          << (t->tm_sec < 10 ? "0" : "") << t->tm_sec
	          << "] ";
}

void Account::makeDeposit(int deposit)
{
	const int previous_amount = _amount;

	_amount += deposit;
	_nbDeposits += 1;
	_totalAmount += deposit;
	_totalNbDeposits += 1;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
	          << ";p_amount:" << previous_amount
	          << ";deposit:" << deposit
	          << ";amount:" << _amount
	          << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	const int previous_amount = _amount;

	if ((_amount - withdrawal) < 0)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex
		          << ";p_amount:" << _amount 
		          << ";withdrawal:refused" << std::endl;
		return (false);
	}
	
	_amount -= withdrawal;
	_nbWithdrawals += 1;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals += 1;
	
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";p_amount:" << previous_amount 
	          << ";withdrawal:" << withdrawal
	          << ";amount:" << _amount 
	          << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}