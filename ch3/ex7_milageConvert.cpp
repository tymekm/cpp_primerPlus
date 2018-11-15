// ex7_milageConvert.cpp - Converts european liter/100 to miles per gallon.
#include <iostream>

int main()
{
	std::cout << "Enter your petrol usage in liters over 100 km:_\b";
	float liter;
	std::cin >> liter;

	const float literToGallon = 0.26417;

	int mpg = 62.14 / (liter * literToGallon);

	std::cout << "You milage is equal to " << mpg << " mpg" << std::endl;
}


