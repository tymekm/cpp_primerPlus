#include <iostream>
#include "Mean.h"
#include <cmath>

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;

    double x,y,z;

    cout << "Enter two numbrers: ";
    while (cin >> x >> y)
    {
	try {
	    z = hmean(x,y);
	    cout << "Harmonic mean of " << x << " and " << y << 
		" is " << z << '\n';
	    cout << "Geometric mean of " << x << " and " << y <<
		" is " << gmean(x,y) << '\n';
	    cout << "Enter next set of numbers <q to quit>: ";
	}
	catch (bad_hmean & bg)
	{
	    cout << bg.what() << '\n';
	    cout << "Try again.\n";
	    continue;
	}
	catch (bad_gmean & hg)
	{
	    cout << hg.what() << '\n';
	    cout << "Values used: " << x << ", " << y << '\n';
	    cout << "Sorry, you don't get to play anymore.\n";
	    break;
	}
    }
    cout << "Bye!\n";
}

double hmean(double a, double b)
{
    if ( a == -b)
	throw bad_hmean();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
	throw bad_gmean();
    return std::sqrt( a*b );
}
