#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using std::string;

class Account
{
public:
    Account();
    Account(string name, string accountnumber, int balance);
    void showaccount();
    void deposit(const int deposit);
    void widthdraw(const int toWithdraw);
    
private:
    string name;
    string accountNumber;
    int balance;
};

#endif
