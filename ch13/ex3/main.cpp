#include "Dma.h"
#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    
    char choice;
    const int MAX = 10;
    DmaABC * dmaArr[MAX];

    for (int i = 0; i < MAX; i++) 
    {
	cout << "Choose class:\n" << "1)BaseDma\t2)LacksDma\t3)HasDma: ";
	while(cin >> choice && (choice != '1' && choice != '2' && choice != '3'))
	    cout << "Please choose 1, 2 or 3: ";

	if (choice == '1')
	{
	    char * l = new char[256];
	    int r;
	    cout << "Label: ";
	    cin >> l;
	    cout << "Rating: ";
	    cin >> r; 
	    dmaArr[i] = new BaseDma(l,r);
	    delete [] l;
	}
	else if (choice == '2')
	{
	    char * c = new char[256];
	    cout << "Color: ";
	    cin >> c;
	    dmaArr[i] = new LacksDma(c);
	    delete [] c;
	}
	else if (choice == '3')
	{
	    char * s = new char[256];
	    cout << "Style: ";
	    cin >> s;
	    dmaArr[i] = new HasDma(s);
	    delete [] s;
	}
    }

    for (int i = 0; i < MAX; i++) 
    {
	dmaArr[i]->show();
	cout << '\n';
    }
}
