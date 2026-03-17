#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += _amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
}

int Account::getNbAccounts()
{
	return _nbAccounts;
}

int Account::getTotalAmount()
{
	return _totalAmount;
}
int Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals()
			  << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount = _totalAmount + deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";";

	_amount = _amount + deposit;
	std::cout << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits
			  << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "withdrawal:";

	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return false;
	}

	std::cout << withdrawal << ";";

	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount = _totalAmount - withdrawal;
	_amount = _amount - withdrawal;

	std::cout << "amount:" << _amount << ";"
			  << "nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	return true;
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t t = time(0);

	char buff[80];
	strftime(buff, 80, "%Y%m%d_%H%M%S", localtime(&t));
	std::cout << "[" << buff << "] ";
}