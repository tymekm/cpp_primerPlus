// ex7.cpp - Creates and initializes a structure, then fills in values from
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
	inflatable pizza;

	std::cout << "Enter the name of the pizza company: ";
	std::cin >> pizza.name;

	std::cout << "Enter the pizza diameter: ";
	std::cin >> pizza.diameter;

	std::cout << "Enter the pizza weight: ";
	std::cin >> pizza.weight;

	std::cout << 
		"Company: " << pizza.name <<
		"\nDiameter: " << pizza.diameter <<
		"\nWeight: " << pizza.weight
	<< std::endl;
}
