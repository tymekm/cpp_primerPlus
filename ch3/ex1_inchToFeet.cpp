// ex1_inchToFeet.cpp - converts inches to inches and feet.
#include <iostream>

int main()
{
	const int feetToInch = 12;
	std::cout << "Enter your hieght in inches:______\b\b\b\b\b\b";
	int height;
	std::cin >> height;

	int feet = height / feetToInch;
	int inch = height % feetToInch;
	std::cout << "Your weight is " << feet << " feet and " << inch << " inch";
}
