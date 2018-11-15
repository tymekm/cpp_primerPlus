#include "Worker.h"
#include "Queue.h"
#include <iostream>
#include <cstring>

const int SIZE = 2;

int main()
{
    using std::cin;
    using std::cout;
    using std::strchr;

    Queue<Worker*> workersQueue(SIZE);

    Worker * temp;

    int ct = 0;
    while (1)
    {
        char choice;
            cout << "w: waiter   s: singer\n"
            << "t: singing waiter   p: print\n"
            << "d: delete employee  q: quit\n";
        cin >> choice;
        while (strchr("wstqpd", choice) == NULL)
        {
            cout << "Please enter a w, s, t, p, d or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice) 
        {
            case 'w':
        	temp = new Waiter;
		ct++;
        	break;
            case 's':
        	temp = new Singer;
		ct++;
        	break;
            case 't':
        	temp = new SingerWaiter;
		ct++;
        	break;
	    case 'p':
		for (int i = 0; i < ct; i++) 
		{
		    cout << "#" << i + 1 << ' ';
		    workersQueue[i]->show();
		    cout << '\n';
		}
		break;
	    case 'd':
		int toDel;
		cout << "Which entry would you like to delete?: ";
		cin >> toDel;
		workersQueue.deQueue(workersQueue[toDel - 1]);
		ct--;
        }
        cin.get();
        if (strchr("wst", choice))
	{
		temp->set();
	    if (!workersQueue.endQueue(temp))
	    {
		cout << "Queue is full !\n";
		ct--;
	    }
	}
    }
    cout << "Bye.\n";
    delete temp;
    return 0;
}
