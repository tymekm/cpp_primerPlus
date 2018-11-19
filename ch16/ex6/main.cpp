#include <iostream>
#include <queue>
#include "Queue.h"
const int MIN_PER_HOUR = 60;

bool newCustomer(double x);

int main()
{
    using std::cout;
    using std::cin;
    using std::ios_base;
    using std::queue;
    std::srand(time(0));

    cout << "Case study: Bank of Heather Automatic Teller\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "Enter then number of simulation hours: ";
    int hours;
    cin >> hours;
    long cycleLimit = MIN_PER_HOUR * hours;

    cout << "Enter the average number of customers per hour: ";
    double perHour;
    cin >> perHour;
    double min_per_cust;
    min_per_cust = MIN_PER_HOUR / perHour;
    
    Customer temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    int wait_time = 0;
    long line_wait = 0;

    for (int cycle = 0; cycle < cycleLimit; cycle++) 
    {
        if (newCustomer(min_per_cust))
	{
	    if(line.isFull())
		turnaways++;
	    else
	    {
		customers++;
		temp.set(cycle);
		line.endQueue(temp);
	    }
	}
	if (wait_time <= 0 && !line.isEmpty())
	{
	    line.deQueue();
	    wait_time = temp.ptime();
	    line_wait += cycle - temp.when();
	    served++;
	}
	if (wait_time > 0)
	    wait_time--;
	sum_line += line.queueCount();
    }

    if (customers > 0)
    {
	cout << "customers accepted: " << customers << '\n';
	cout << "  customers served: " << served << '\n';
	cout << "         turnaways: " << turnaways << '\n';
	cout << "average queue size: ";
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << (double) sum_line / cycleLimit << '\n';
	cout << " average wait time: "
	    << (double) line_wait / served << " minutes\n";
    }
    else
	cout << "No customers!\n";
    cout << "Done!\n";
    return 0;
}

bool newCustomer(double x)
{
    return (std::rand() * x / RAND_MAX < 1);
}
