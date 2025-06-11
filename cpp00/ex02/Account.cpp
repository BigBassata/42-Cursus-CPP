/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: licohen <licohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:45:35 by licohen           #+#    #+#             */
/*   Updated: 2025/05/23 15:22:31 by licohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"


/* Les var statiques declarees dans une classe doivent etre definies(init) en 
dehors de la classe, dans un fichier .cpp, ces lignes n appartiennent a aucun objet
elles init l espace memoire partage par tout les objets Account.*/
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0; 

/* Implementation du constructeur
A la creation d un objet Account, le constructeur init la valeurs propres a ces ojets (_amount, _accountIndex, ...)
met a jour les valeurs partagees (statique) comme _nbAccounts, _totalAmounts, et 
affiche un log de creation, dans le format demande*/

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
/* implentation du destructeur 
Methode special appele automatiquement quand un objet est detruit(fin de prog, fin de portee, delete etc ..)
Afficher un message indiquant que le compte est ferme, ne dois pas modifier les membres statiques globaux 
comme _nbAccounts. */
Account::~Account(void) 
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
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

void	Account::_displayTimestamp(void)
{
	std::time_t now = std::time(NULL);
	struct tm *t = std::localtime(&now); // Convertir en heure locale

	// Afficher le timestamp formaté
	std::cout << "["
			  << (t->tm_year + 1900)   // Année
			  << (t->tm_mon + 1 < 10 ? "0" : "") << (t->tm_mon + 1)
			  << (t->tm_mday < 10 ? "0" : "") << t->tm_mday
			  << "_"
			  << (t->tm_hour < 10 ? "0" : "") << t->tm_hour
			  << (t->tm_min < 10 ? "0" : "") << t->tm_min
			  << (t->tm_sec < 10 ? "0" : "") << t->tm_sec
		      << "] ";
}

// Setters for Account class:
void	Account::makeDeposit(int deposit)
{
	const int	previous_amount = _amount;

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

bool	Account::makeWithdrawal(int withdrawal)
{
	const int	previous_amount = _amount;

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