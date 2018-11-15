// ex9.cpp - ex6 but with dynamic structres.
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
	candyBar * ps = new candyBar;

	*ps =
	{
		"Prince Polo",
		3.3,
		450
	};

	std::cout << 
		"Snack name: " << ps->name <<
		"\nSnack weight: " << ps->weight <<
		"\nSnack calories: " << ps->calories
	<< std::endl;

	*ps =
	{
		"Mocha munch",
		2.3,
		350
	};

	std::cout << 
		"Snack name: " << ps->name <<
		"\nSnack weight: " << ps->weight <<
		"\nSnack calories: " << ps->calories
	<< std::endl;

	*ps =
	{
		"Mars",
		2.3,
		550
	};

	std::cout << 
		"Snack name: " << ps->name <<
		"\nSnack weight: " << ps->weight <<
		"\nSnack calories: " << ps->calories
	<< std::endl;

	delete ps;
}
