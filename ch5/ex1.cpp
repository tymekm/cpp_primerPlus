// ex2.cpp - Sum all whole numbers from input one to two.
#include <iostream>

int main()
{
	int nfirst;
	int nsecond;
	int sum = 0;

	std::cout << "Enter first interger__\b\b";
	std::cin >> nfirst;


	std::cout << "Enter second interger__\b\b";
	std::cin >> nsecond;

	for (; nfirst < nsecond + 1; nfirst++) 
	{
		sum += nfirst;
	}

	std::cout << sum << std::endl;
}
