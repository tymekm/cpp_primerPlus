// ex8.cpp - Creates and initializes a dynamic structure, then fills in values from
// user input.
#include <iostream>
#include <string>

struct inflatable
{
	std::string name;
	int diameter;
	int weight;
};

int main()
{
	inflatable * ps = new inflatable;

	std::cout << "Enter the pizza diameter: ";
	std::cin >> ps->diameter;

	std::cout << "Enter the name of the pizza company: ";
	std::cin >> ps->name;

	std::cout << "Enter the pizza weight: ";
	std::cin >> ps->weight;

	std::cout << 
		"Company: " << ps->name <<
		"\nDiameter: " << ps->diameter <<
		"\nWeight: " << ps->weight
	<< std::endl;

	delete ps;
}
