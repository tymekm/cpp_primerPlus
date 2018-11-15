// ex10.cpp - Get user input into array, calculate average and cout vlaues.
#include <iostream>

int main()
{
	float  fsprintTimes[3];

	std::cout << "Enter time for first run:__\b\b";
	std::cin >> fsprintTimes[0];

	std::cout << "Enter time for second run:__\b\b";
	std::cin >> fsprintTimes[1];

	std::cout << "Enter time for third run:__\b\b";
	std::cin >> fsprintTimes[2];

	float fsprintAverage = (fsprintTimes[0] + fsprintTimes[1] + fsprintTimes[2]) /3;

	std::cout << "\nThe time of your first run was: " << fsprintTimes[0] << std::endl;
	std::cout << "The time of your second run was: " << fsprintTimes[1] << std::endl;
	std::cout << "The time of your third run was: " << fsprintTimes[2] << std::endl;

	std::cout << "\nYou average time is: " << fsprintAverage << std::endl;

	return 0;
}
