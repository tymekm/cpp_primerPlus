#include <iostream>
#include <algorithm>
#include "sales.h"


namespace SALES
{
    using std::cout;
    using std::cin;
    using std::sort;

    void setSales(Sales& s, const double arr[], int n)
    {
	double total;
	for (int i = 0; i < n; i++) 
	{
	    s.sales[i] = arr[i];
	    total += arr[i];
	}

	s.average = total /n;

	sort(s.sales, s.sales + n);

	s.min = s.sales[0];
	s.max = s.sales[n - 1];
    }

    void setSales(Sales& s)
    {
	cout << "Please enter the sales for the first quarter:\n";

	double total;
	for (int i = 0; i < QUARTERS ; i++) 
	{
	    cout << "Please enter the sales for quarter #" << i << " : ";
	    std::cin >> s.sales[i];
	    while (!cin)
	    {
		cout << "Illegal value entered, enter a number\n";
		cout << "Please enter the sales for quarter #" << i << " : ";
		cin.clear();
		cin.ignore();
		std::cin >> s.sales[i];
	    }
	    total += s.sales[i];
	}
	s.average = total / QUARTERS;

	sort(s.sales, s.sales + QUARTERS);

	s.min = s.sales[0];
	s.max = s.sales[QUARTERS - 1];
    }

    void showSales(const Sales& s)
    {
	for (int i = 0; i < QUARTERS; i++) 
	{
	    cout << "Sales for quarter #";
	    cout << i+1 << ": " << s.sales[i] << '\n';
	}

	cout << "\nAverage quarterly sales: " << s.average << '\n';
	cout << "Highest quarterly sales: " << s.max << '\n';
	cout << "Lowest quarterly sales: " << s.min << '\n';
    }
}
