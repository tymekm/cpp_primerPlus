// ex5.cpp - Creates and initializes a simple structure.
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
	candyBar snack =
	{
		"Mocha munch",
		2.3,
		350
	};

	std::cout << 
		"Snack name: " << snack.name <<
		"\nSnack weight: " << snack.weight <<
		"\nSnack calories: " << snack.calories

	<< std::endl;
}
