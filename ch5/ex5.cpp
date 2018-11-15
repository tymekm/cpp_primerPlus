// ex5.cpp
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

	int sales[12];

	for(int i = 0; i < 12; i++)
	{
		std::cout << "Enter the sales numbers for " << months[i] << std::endl;
		std::cin >> sales[i];
		
	}

	int sum = 0;
	for (int i = 0; i < 12; i++) 
	{
		sum += sales[i];			
	}

	std::cout << "\nThe total sales for the year were: " << sum << std::endl;
}
