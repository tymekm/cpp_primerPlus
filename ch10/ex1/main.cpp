#include <iostream>
#include <string>
#include "account.h"

int main()
{
    Account john {"John Smith", "84732947", 5000};
    john.showaccount();

    john.deposit(567);
    john.showaccount();

    john.widthdraw(987);
    john.showaccount();

    john.widthdraw(476882);
    john.showaccount();

    return 0;
}

