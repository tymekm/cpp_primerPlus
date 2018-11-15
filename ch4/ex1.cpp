// ex1.cpp - put user info into stuct and display it.
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
	std::cin.get(guest.firstName, 20);

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
