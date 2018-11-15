#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
#include <vector>
const int MIN_PER_HR = 60;
const int queueSize = 10;
const int hours = 1000;

bool newCustomer(double x);
double runSimulation(int hours, int queueSize, int perHour);

using std::cin;
using std::cout;
using std::ios_base;

int main()
{

    std::srand(std::time(0));
    cout << "Case study: Bank of Heather Automatic Teller\n";
    cout << "Using maximum of 10 poeple in line to find value of " <<
	"customers per hour resulting in average wait time of 1 minute.\n";
    
    std::vector<double> desiredRange;
    for (int perHour = 1; perHour < 101; perHour++) 
    {
	int temp = runSimulation(hours, queueSize, perHour) + 0.5;    
	if (temp == 1)
	    desiredRange.push_back(perHour);
    }

    if (desiredRange.empty())
	cout << "No values resulted in a average wait time of 1 minute.\n";
    else
	cout << desiredRange.front() << " up to " << desiredRange.back()
	    <<" customers per hour resulted in an average wait time of 1 minute.\n";

    cout << "Done!\n";
    return 0;
}

double runSimulation(int hours, int queueSize, int perHour)
{
    Queue line(queueSize);
    long cyclelimit = MIN_PER_HR * hours;

    double min_per_cust;
    min_per_cust = MIN_PER_HR / perHour;

    Customer temp;
    double averageWait = 0;
    long turnAways = 0;
    long customers = 0;
    long served = 0;
    long sumLine = 0;
    int waitTime = 0;
    long lineWait = 0;

    for (int cycle = 0; cycle < cyclelimit; cycle++)
    {
	if (newCustomer(min_per_cust))
	{
	    if (line.isFull())
		turnAways++;
	    else
	    {
		customers++;
		temp.set(cycle);
		line.endQueue(temp);
	    }
	}
	if (waitTime <= 0 && !line.isEmpty())
	{
	    line.deQueue(temp);
	    waitTime = temp.ptime();
	    lineWait += cycle - temp.when();
	    served++;
	}
	if (waitTime > 0)
	    waitTime--;
	sumLine += line.queueCount();
    }

    if (customers > 0)
    {
	averageWait = (double) lineWait / served;
    }
    else
	cout << "No customers!\n";
    return averageWait;
}

bool newCustomer(double x)
{
    return  (std::rand() * x / RAND_MAX < 1);
}
