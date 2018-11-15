// ex5_popPercent.cpp - converts inches to inches and feet.
#include <iostream>

int main()
{
	std::cout << "Enter the world population:_\b";
	long long worldPop;
	std::cin >> worldPop;
	std::cout << "Enter the population of the US:_\b";
	long long usPop;
	std::cin >> usPop;

	float popPercent = float(usPop) / float(worldPop) * 100;

	std::cout << "The population of the US is " <<
	popPercent << "%" << " of the world population"
	<< std::endl;
}


