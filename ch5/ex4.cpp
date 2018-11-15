// ex4.cpp
#include <iostream>
#include <array>

int main()
{
	int daphne = 100;
	int cleo = 100;
	int years = 0;

	while(daphne >= cleo)
	{
		daphne += 10;	

		cleo += (cleo / 20);
		years ++;
	}

	std::cout << "After " << years << " years Cleo's balance exeeded Daphne's," << std::endl;
	std::cout << "with balances of $" << cleo << " and $" << daphne << " respectively." << std::endl;
}
