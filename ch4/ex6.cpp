// ex6.cpp - Creates and initializes a array of structures.
#include <iostream>
#include <string>

struct candyBar
{
	std::string name;
	float weight;
	int calories;
};

int main()
{
	candyBar snack[3];

	snack[0] =
	{
		"Prince Polo",
		3.3,
		450
	};

	snack[1] =
	{
		"Mocha munch",
		2.3,
		350
	};

	snack[2] =
	{
		"Mars",
		2.3,
		550
	};

	std::cout << 
		"Snack name: " << snack[0].name <<
		"\nSnack weight: " << snack[0].weight <<
		"\nSnack calories: " << snack[0].calories
	<< std::endl;
	std::cout << 
		"Snack name: " << snack[1].name <<
		"\nSnack weight: " << snack[1].weight <<
		"\nSnack calories: " << snack[1].calories
	<< std::endl;
	std::cout << 
		"Snack name: " << snack[2].name <<
		"\nSnack weight: " << snack[2].weight <<
		"\nSnack calories: " << snack[2].calories
	<< std::endl;
}
