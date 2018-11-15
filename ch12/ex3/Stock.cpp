#include "Stock.h"
#include <cstring>

using std::strcpy;
using std::strlen;

Stock::Stock()
{
    company = new char[8];
    strcpy(company, "no name");
    shares = share_val = total_val = 0;
}

Stock::Stock(const char * c, long n, double pr)
{
    company = new char[strlen(c) + 1];
    strcpy(company, c);
    if (n < 0)
    {
	cout << "Number of shares can't be negative; "
	    << company << " shares set to 0.\n";
	shares = 0;
    }
    else
    shares = n;
    share_val = pr;
    set_tot();
}

Stock::~Stock()
{
    delete [] company;
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
	cout << "Number of shares purchaces can't be negative. "
	    << "Transaction aborted.\n";
    }
    else
    {
	shares += num;
	share_val = price;
	set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    {
	cout << "Number of shares purchaces can't be negative. "
	    << "Transaction aborted.\n";
    }
    else if (num > shares)
    {
	cout << "Insifficient shares!"
	    << "Transaction aborted.\n";
    }
    else
    {
	shares -= num;
	share_val = price;
	set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
	return s;
    else
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Stock & stock)
{
    using std::ios_base;
    ios_base::fmtflags orig = 
	cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(2); 

    cout << "Company: " << stock.company
	<< " Shares: " << stock.shares << '\n';
    cout << "Shares Price: $" << stock.share_val << '\n';
    cout << "Total Worth: $" << stock.total_val << '\n';

    cout .setf(orig, ios_base::floatfield);
    cout.precision(prec);
    return os;
}
