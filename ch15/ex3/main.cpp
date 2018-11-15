#include <iostream>
#include "Mean.h"
#include <cmath>

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
    using std::cout;
    using std::cin;

    double x,y,h,g;

    cout << "Enter two numbrers: ";
    while (cin >> x >> y)
    {
	try {
	    h = hmean(x,y);
	    cout << "Harmonic mean of " << x << " and " << y << 
		" is " << h << '\n';
	    g = gmean(x,y);
	    cout << "Geometric mean of " << x << " and " << y <<
		" is " << g << '\n';
	    cout << "Enter next set of numbers <q to quit>: ";
	}
	catch (bad_value * bv)
	{
	   bv->report(); 
	   cout << "Aborting...";
	   break;
	}
    }
    cout << "Bye!\n";
}

double hmean(double a, double b)
{
    if ( a == -b)
    {
	bad_value * except = new bad_hmean(a,b, "hmean");
	throw except;
        delete except;
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
    {
	bad_value * except = new bad_gmean(a,b, "gmean");
	throw except;
        delete except;
    }
    return std::sqrt( a*b );
}
