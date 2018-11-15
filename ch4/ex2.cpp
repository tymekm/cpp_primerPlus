// ex2.cpp - Same as ex1 expect uses string class istead of cstring's.
#include <iostream>
#include <string>

struct info 
{
	std::string firstName;
	std::string lastName;
	int age;
	char grade;
};

int main()
{
	info guest;
	std::cout << "What is your first name? ______\b\b\b\b\b\b";	
	getline(std::cin, guest.firstName);

	std::cout << "Waht is your last name? ______\b\b\b\b\b\b";
	std::cin >> guest.lastName;

	std::cout << "What letter grade do you deserve? _\b";
	std::cin >> guest.grade;
	guest.grade +=1;

	std::cout << "What is your age? __\b\b";
	std::cin >> guest.age;

	std::cout << "Name: " << guest.lastName << ", " << guest.firstName << std::endl;
	std::cout << "Grade: " << guest.grade << std::endl;
	std::cout << "Age: " << guest.age << std::endl;

}
