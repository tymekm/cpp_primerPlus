#include <iostream>
#include <cstring>
#include "Classic.h"

void Bravo(const Cd & disk);

int main()
{
    using std::cout;

    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano sonata in B flat, Fantasia in C",
	    "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();

    cout << "Using type cd * pointer to object:\n";
    pcd->Report();
    pcd = &c2;
    pcd->Report();

    cout << "Calling a function with Cd referance argument:\n";
    Bravo(c1);
    Bravo(c2);

    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd & disk)
{
    disk.Report();
}

