// ex6_milage.cpp - Calculate the milage given distance and fuel used.
#include <iostream>

int main()
{
	std::cout << "What distance have you driven in kilometers:_\b";
	int distance;
	std::cin >> distance;
	std::cout << "How many liters of petrol have you used:_\b";
	int petrol;
	std::cin >> petrol;

	float milage = float(petrol) / float(distance) * 100;

	std::cout << "Your milage is " << milage <<
	"/100"	
	<< std::endl;


}


