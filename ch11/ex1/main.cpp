#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    using VECTOR::Vector;

    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int itteration;

    std::ofstream fout;
    fout.open("random_walker-out");
    cout << "Enter target distance (q to quit)";
    while (cin >> target)
    {
	cout << "Enter step length: ";
	if (!(cin >> dstep))
	    break;

	fout << "Target distance: " << target << ", Step size: " << 
	    dstep << '\n';

	while (result.magval() < target)
	{
	    if (steps != 0)
		fout << steps << ": " << result << '\n';
	    direction = rand() % 360;
	    step.reset(dstep, direction, Vector::POL);
	    result = result + step;
	    steps ++;
	}
	fout << "After " << steps << " steps, the subject "
	    "has the following locations:\n";
	cout << "After " << steps << " steps, the subject "
	    "has the following locations:\n";
	fout << result << endl;
	result.polar_mode();
	fout << result << endl;
	cout << result << endl;
	result.polar_mode();
	fout << "Average outward distance per step = "
	    << result.magval()/steps << endl;
	cout << "Average outward distance per step = "
	    << result.magval()/steps << endl;
	steps = 0;
	result.reset(0.0, 0.0);
	cout << "Enter target distance (q to quit): ";
    }
    cout << "Bye\n";
    cout << "ok";
    cin.clear();
    while (cin.get() != '\n')
	continue;
    return 0;
}
