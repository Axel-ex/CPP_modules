/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:57:04 by achabrer          #+#    #+#             */
/*   Updated: 2024/01/26 14:55:55 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) { return (_nbAccounts); }

int Account::getTotalAmount(void) { return (_totalAmount); }

int Account::getNbDeposits(void) { return (_totalNbDeposits); }

int Account::getNbWithdrawals(void) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos(void)
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp(void)
{
    std::time_t time_in_sec = std::time(NULL);
    std::tm *timemark = std::localtime(&time_in_sec);
    char time_buff[20];

    std::strftime(time_buff, 20, "[%Y%m%d_%H%M%S]", timemark);
    std::cout << time_buff << " ";
}

Account::Account(void) { return; }

Account::~Account(void)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

Account::Account(int initial_deposit)
    : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    this->_accountIndex = this->_nbAccounts;
    this->_nbAccounts++;
    this->_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    _totalAmount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > this->_amount)
    {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex << ";";
        std::cout << "p_amount:" << this->_amount << ";";
        std::cout << "withdrawal:refused" << std::endl;
        return (false);
    }
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:" << withdrawal << ";";
    this->_amount -= withdrawal;
    _totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

void Account::displayStatus() const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

int Account::checkAmount(void) const { return (this->_amount); }