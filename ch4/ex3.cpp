// ex3.cpp - Get user name and last name and cout as single line.
#include <iostream>
#include <cstring>

struct info 
{
	char firstName[20];
	char lastName[20];
	int age;
	char grade;
};

int main()
{
	info guest;
	std::cout << "What is your first name? ______\b\b\b\b\b\b";	
	std::cin >> guest.firstName;

	std::cout << "Waht is your last name? ______\b\b\b\b\b\b";
	std::cin >> guest.lastName;

	std::cout << 
		"Here's the information in a single string: " <<
		guest.lastName << ", " << guest.firstName
	<< std::endl;
}
