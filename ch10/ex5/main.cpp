#include "stack.h"
#include <iostream>
#include <string>
#include <cctype>

int main()
{
    using std::string;
    using std::cout;
    using std::cin;

    Stack st;

    char ch;
    Item item;

    cout << "Please enter A to add a customer,\n";
    cout << "R to remove a customer, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
	while (cin.get() != '\n')
	    continue;
	if (!isalpha(ch))
	{
	    cout << '\a';
	    continue;
	}
	switch (ch)
	{
	    case 'A':
	    case 'a':
		cout << "Enter cursomer name: ";
		getline(cin, item.fullname);
		cout << "\nEnter payment amount: ";
		cin >> item.payment;
		cin.clear();
		cin.ignore();
		if (st.isFull())
		    cout << "\nStack already full!\n";
		else 
		    st.push(item);
		break;

	    case 'R':
	    case 'r':

		if (st.isEmpty())
		    cout << "\nStack already empty!\n";
		else
		{
		    cout << "Customer " << item.fullname << " removed.\n";
		    st.pop(item);
		}
		break;
	}
	cout << "Please enter A to add a customer,\n";
	cout << "R to remove a customer, or Q to quit.\n";
    }
    cout << "Done.\n";
    return 0;
}
