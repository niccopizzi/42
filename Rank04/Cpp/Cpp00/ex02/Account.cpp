/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npizzi <npizzi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:22:52 by npizzi            #+#    #+#             */
/*   Updated: 2025/02/10 17:53:59 by npizzi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <ctime>
#include <iostream>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(void)
{
    return (_nbAccounts);
}
int	Account::getTotalAmount(void)
{
    return(_totalAmount);
}
int	Account::getNbDeposits(void)
{
    return(_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
    return(_totalNbWithdrawals);
}
void	Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount 
            << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account(int initial_deposit)
{
    _displayTimestamp();
    this->_accountIndex = _nbAccounts;
    Account::_nbAccounts ++;
    if (initial_deposit < 0)
        initial_deposit = 0;
    this->_amount = initial_deposit;
    Account::_totalAmount += initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    std::cout << "index:" << _accountIndex << ";amount:" << initial_deposit << ";created\n";
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
    _nbAccounts --;
    _totalAmount -= _amount;
}

void	Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    if (deposit <= 0)
        deposit = 0;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    _amount += deposit;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount;
    _nbDeposits ++;
    std::cout << ";nb_deposits:" << _nbDeposits << "\n";
    Account::_totalNbDeposits ++;
    Account::_totalAmount += deposit;
}
bool	Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    if (withdrawal > _amount)
    {
        std::cout << ";withdrawal:refused\n";
        return (false);
    }
    _amount -= withdrawal;
    _nbWithdrawals ++;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals << "\n";
    Account::_totalNbWithdrawals++; 
    Account::_totalAmount -= withdrawal;
    return (true);
}
int		Account::checkAmount(void) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals << "\n";
}


void    Account(void)
{
}

void    Account::_displayTimestamp()
{
    std::time_t t;
    std::tm*     time;
    
    t = std::time(0);
    time = std::localtime(&t);
    std::cout << "[" <<(time->tm_year) + 1900
            <<std::setfill('0')<<std::setw(2)<<(time->tm_mon) + 1
            <<std::setfill('0')<<std::setw(2)<<time->tm_mday<<"_" 
            <<std::setfill('0')<<std::setw(2)<<time->tm_hour
            <<std::setfill('0')<<std::setw(2)<<time->tm_min
            <<std::setfill('0')<<std::setw(2)<<time->tm_sec<<"] ";
}