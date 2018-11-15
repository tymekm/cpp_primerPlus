#include "Stock.h"

const int STKS = 4;
int main()
{
    Stock stocks[STKS] = 
    {
	Stock("NanoSmart", 12, 20.0),
	Stock("Baffo Objects", 200, 2.0),
	Stock("Monolithic Obeliscs", 130, 3.25),
	Stock("Fleep Enterprises", 60, 6.5),
    };

    std::cout << "Stock holdings:\n";
    int st;
    for (int i = 0; i < STKS; i++) 
    {
        cout << stocks[i];
    }
    const Stock * top = &stocks[0];
    for (st = 1; st < STKS; st++) 
    {
	top = &top->topval(stocks[st]);     
    }
    cout << "\nMost valuable holding:\n"
	<< *top;
    return 0;
}
