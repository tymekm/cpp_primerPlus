// ex6.cpp
#include <iostream>
#include <string>

int main()
{
	std::string months[12] = 
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"October",
		"September",
		"November",
		"December"
	};

	int sales[3][12];

	for (int i = 0; i < 3; i++) 
	{
		std::cout << "Enter the sales numbers for year: " << i << std::endl;
		for(int j = 0; j < 12; j++)
		{
			std::cout << "month: " << months[j] << std::endl;
			std::cin >> sales[i][j];
			
		}
	}


	int yearlyTot[3];

	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 12; j++) 
		{
			yearlyTot[i] += sales[i][j];			
		}
	}

	std::cout << "\nThe total sales for the year: 1 were: " << yearlyTot[0] << std::endl;
	std::cout << "\nThe total sales for the year: 2 were: " << yearlyTot[1] << std::endl;
	std::cout << "\nThe total sales for the year: 3 were: " << yearlyTot[2] << std::endl;

	std::cout << "Total sames amount to: " << yearlyTot[0] + yearlyTot[1] + yearlyTot[2] << std::endl;
}
