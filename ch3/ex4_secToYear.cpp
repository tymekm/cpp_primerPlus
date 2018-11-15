// ex4_secToYear.cpp - converts inches to inches and feet.
#include <iostream>

int main()
{
	const int secToMin = 60;
	const int minToHour = 60;
	const int hourToDay = 24;

	std::cout << "Enter the number of seconds:_\b";
	unsigned long long seconds = 31600000;
	//unsigned long long seconds;
	//std::cin >> seconds;

	int days = seconds / (hourToDay * minToHour * secToMin);
	unsigned long sec =  seconds % (hourToDay * minToHour * secToMin);

	int hours = sec / (minToHour * secToMin);
	sec =  sec % (minToHour * secToMin);

	int min = sec / secToMin;
	sec = sec % secToMin;

	std::cout << seconds << " seconds = " <<
	days << " days, " << hours << " hours, " <<
	min << " minutes, " << sec << " seconds"

	<< std::endl;
}


