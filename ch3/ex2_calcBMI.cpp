// ex2_calcBMI.cpp - converts inches to inches and feet.
#include <iostream>
#include <cmath>

int main()
{
	std::cout << "Enter your height in feet:_\b";
	int feet;
	std::cin >> feet;
	std::cout << "Enter your height in inches:_\b";
	int inches;
	std::cin >> inches;
	std::cout << "Enter your weight in pounds:_\b";
	int pounds;
	std::cin >> pounds;
	

	const int feetToInches = 12;
	const float inchesToMeter = 0.0254;
	const float poundsToKg = 2.2;
	
	float height = (feet * feetToInches + inches) * inchesToMeter;
	float weight = pounds / poundsToKg;	

	int bmi;
	bmi = weight / std::sqrt(height);

	std::cout << "You BMI is: " << bmi << std::endl;
}

