#include "Sales.h"
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    double vals1[12] =
    {
	1220, 1100, 1122, 2212, 1232, 2334,
	2884, 2394, 3302, 2922, 3002, 3544
    };

    double vals2[12] = 
    {
	12, 11, 22, 21, 32, 34,
	28, 29, 33, 29, 32, 35
    };

    Sales sales1(2001, vals1, 12);
    LabeledSales sales2("Blogstar", 2012, vals2, 12);

    cout << "First try block:\n";
    try
    {
	int i;
	cout << "Year = " << sales1.Year() << '\n';
	for (int i = 0; i < 12; i++) 
	{
	    cout << sales1[i] << ' ';
	    if (i % 6 == 5)
		cout << '\n';
	}
	cout << "Year = " << sales1.Year() << '\n';
	cout << "Label = " << sales2.Label() << '\n';
	for (int i = 0; i <= 12; i++) 
	{
	    cout << sales2[i] << ' ';
	    if (i % 6 ==5)
		cout << '\n';
	}
	cout << "End of try block 1.\n";
    }
    catch (Sales::bad_index * bad)
    {
	cout << bad->what();
	if (typeid(LabeledSales::nbad_index) == typeid(*bad))
	    cout << "Company: " << bad->label_val() << '\n';
	cout << "bad index: " << bad->bi_val() << '\n';
    }
    cout << "\nNext try block:\n";
    try 
    {
	sales2[2] = 37.5;
	sales1[20] = 23345;
	cout << "End of try block 2.\n";
    }
    catch (Sales::bad_index * bad)
    {
	cout << bad->what();
	if (typeid(LabeledSales::nbad_index) == typeid(*bad))
	    cout << "Company: " << bad->label_val() << '\n';
	cout << "bad index: " << bad->bi_val() << '\n';
    }
    cout << "done\n";
}
