// ex4.cpp - Same as ex3 exept with th string class.
#include <iostream>
#include <string>

int main()
{

	std::string firstName;
	std::string lastName;

	std::cout << "What is your first name? ______\b\b\b\b\b\b";	
	std::cin >> firstName;

	std::cout << "Waht is your last name? ______\b\b\b\b\b\b";
	std::cin >> lastName;

	std::string fullName = lastName + ", " + firstName;

	std::cout << 
		"Here's the information in a single string: " <<
		fullName
	<< std::endl;
}
