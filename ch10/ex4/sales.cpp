#include <iostream>
#include <algorithm>
#include "sales.h"


namespace SALES
{
    using std::cout;
    using std::cin;
    using std::sort;

    Sales::Sales(const double arr[], int n)
    {
	double total;
	for (int i = 0; i < n; i++) 
	{
	    Sales::sales[i] = arr[i];
	    total += arr[i];
	}

	Sales::average = total /n;

	sort(Sales::sales, Sales::sales + n);

	Sales::min = Sales::sales[0];
	Sales::max = Sales::sales[n - 1];
    }

    Sales::Sales()
    {
	cout << "Please enter the sales for the first quarter:\n";

	double total;
	for (int i = 0; i < Sales::QUARTERS ; i++) 
	{
	    cout << "Please enter the sales for quarter #" << i << " : ";
	    std::cin >> Sales::sales[i];
	    while (!cin)
	    {
		cout << "Illegal value entered, enter a number\n";
		cout << "Please enter the sales for quarter #" << i << " : ";
		cin.clear();
		cin.ignore();
		std::cin >> Sales::sales[i];
	    }
	    total += Sales::sales[i];
	}
	Sales::average = total / QUARTERS;

	sort(Sales::sales, Sales::sales + QUARTERS);

	Sales::min = Sales::sales[0];
	Sales::max = Sales::sales[QUARTERS - 1];
    }

    void Sales::showSales()
    {
	for (int i = 0; i < Sales::QUARTERS; i++) 
	{
	    cout << "Sales for quarter #";
	    cout << i+1 << ": " << Sales::sales[i] << '\n';
	}

	cout << "\nAverage quarterly sales: " << Sales::average << '\n';
	cout << "Highest quarterly sales: " << Sales::max << '\n';
	cout << "Lowest quarterly sales: " << Sales::min << '\n';
    }
}
