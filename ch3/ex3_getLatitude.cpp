// ex3_getLatitude.cpp - converts inches to inches and feet.
#include <iostream>

int main()
{

	std::cout << "Please enter the degrees:_\b";
	int degree;
	std::cin >> degree;
	std::cout << "Please enter the minutes of arc:_\b";
	int min;
	std::cin >> min;
	std::cout << "Please enter the seconds of arc:_\b";
	int sec;
	std::cin >> sec;

	const int minToDegree = 60;
	const int secToDegree = 60;


	float finalDegree = degree + (float(min) / float(minToDegree)) + float(float(sec) / float(secToDegree));
	std::cout << degree << "degrees, " << min << " minutes, " << sec << " seconds = " << finalDegree << " degrees" << std::endl;
}

