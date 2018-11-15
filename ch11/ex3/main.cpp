#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include "vector.h"

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    using std::vector;
    using VECTOR::Vector;

    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    int trials;
    vector<unsigned long> resultsArr;

    cout << "Enter number of trials to run (q to quit): ";
    cin >> trials;
    cout << "Enter target distance: ";
    cin >> target;
    cout << "Enter step length: ";
    if (!(cin >> dstep))
	return 0;

    for (int i = 0; i < trials; i++) 
    {
	while (result.magval() < target)
	{
	    direction = rand() % 360;
	    step.reset(dstep, direction, Vector::POL);
	    result = result + step;
	    steps ++;
	}
	resultsArr.push_back(steps);
	steps = 0;
	result.reset(0.0, 0.0);
    }

    std::sort(resultsArr.begin(), resultsArr.end());

    auto lowest = resultsArr.front();
    auto heighest = resultsArr.back();
    unsigned long resultsSum;

    for (auto & n: resultsArr) 
	resultsSum +=n;

    auto average = resultsSum / trials;

    cout << "Lowest amount of steps: " << lowest << "\nHeighest: " << heighest
	<< "\nAverage: " << average << '\n';

    cout << "Bye\n";
    cin.clear();
    while (cin.get() != '\n')
	continue;
    return 0;
}
