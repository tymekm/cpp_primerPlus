#include "stone.h"
#include <iostream>

enum Mode {int_stone, int_pounds};

int main()
{
    using std::cout;
    using std::cin;

    const int SIZE = 6;
    Stone stnArr[SIZE] = {50, 140, 150};

    for (int i = 3; i < SIZE; i++) 
    {
	int mode = int_stone;
	int weight;

	cout << "Array element #" << i + 1 << '\n';
	cout << "What vlaue do you want to enter?\n";
	cout << "1) Stones\t2) Pounds\n";
	cin >> mode;
	while (mode != 1 && mode != 2)
	{
	    cout << "Please enter 1) or 2): ";
	    cin.clear();
	    cin.ignore();
	    cin >> mode;
	}
	mode++;
	cout << "Enter value: ";
	cin >> weight;
	while (!cin)
	{
	    cout << "Please enter a integer: ";
	    cin.clear();
	    cin.ignore();
	    cin >> weight;
	}

	stnArr[i].setValues(weight, mode);
    }

    int biggest = 1;
    int smallest = 1;
    int count = 0;
    Stone stn11(11, int_stone);

    for (int i = 0; i < SIZE; i++) 
    {
	if (stnArr[i] > stnArr[biggest])
	    biggest = i;
	else if (stnArr[i] < stnArr[smallest])
	    smallest = i;
	else if (stnArr[i] >= stn11)
	    count ++;
    }

    cout << "#" << biggest + 1 << " is largest with:\n" << stnArr[biggest] << '\n';
    cout << "#" << smallest + 1 << " is smallest with:\n" << stnArr[smallest] << '\n';
    cout << count << " elements are larger of equal to 11 stone\n";
}
