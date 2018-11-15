#include "Person.h"
#include <iostream>
#include <cstring>

const int MAX = 2;

int main()
{
    using std::cin;
    using std::cout;
    using std::strchr;


    Person * personArr[MAX];

    int ct;
    for (ct = 0; ct < MAX; ct++)
    {
        char choice;
            cout << "g: Gunslinger   p: PokerPlayer'\n"
            << "b: Bad Dude   q: quit\n";
        cin >> choice;
        while (strchr("gpbq", choice) == NULL)
        {
            cout << "Please enter a g, p, b, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice) 
        {
            case 'g': personArr[ct] = new Gunslinger;
        	break;
            case 'p': personArr[ct] = new PokerPlayer;
        	break;
            case 'b': personArr[ct] = new BadDude;
        	break;
        }
        cin.get();
	personArr[ct]->Set();
    }
    cout << "List of the persons: \n";

    int i;
    for (i = 0; i < ct; i++) 
    {
	cout << '\n';
	personArr[i]->Show();
    }
    for (i = 0; i < ct; i++) 
        delete personArr[i];

    cout << "Bye.\n";
    return 0;
}
