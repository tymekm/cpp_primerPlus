// ex7.cpp
#include <iostream>
#include <string>

struct verhicle
{
	std::string make;
	int buildYear;
};

int main()
{
	int arrSize;
	std::cout << "How many cars would you like to enter?" << std::endl;
	std::cin >> arrSize;

	verhicle * car = new verhicle [arrSize];

	for (int i = 0; i < arrSize; i++) 
	{
		std::cout << "Enter data for car " << i << std::endl;		
		std::cout << "Make:____\b\b\b";
		std::cin >> car[i].make;
		std::cout << "Build year:____\b\b\b";
		std::cin >> car[i].buildYear;

	}

	std::cout << "Here's your collection" << std::endl;

	for (int i = 0; i < arrSize; i++) 
	{
	std::cout << car[i].buildYear << " ";
	std::cout << car[i].make << std::endl;
	}

	delete [] car;
}
