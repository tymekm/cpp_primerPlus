#include <iostream>
#include <string>
#include "account.h"


Account::Account()
{
}

Account::Account(string name, string accountnumber, int balance)
{
    Account::name = name;
    Account::accountNumber = accountnumber;
    Account::balance = balance;
}

void Account::showaccount()
{
    using std::cout;
    using std::cin;

    cout << "\nAccount holder: " << Account::name;
    cout << "\naccount number: " << Account::accountNumber;
    cout << "\ncurrent balance: " << Account::balance;
    cout << '\n';
}

void Account::deposit(const int deposit)
{
    Account::balance += deposit;
}

void Account::widthdraw(const int toWithdraw)
{
    if (toWithdraw > Account::balance)
    {
	std::cout << "Insufficient funds!";	
    }
    else
	Account::balance -= toWithdraw;
}
