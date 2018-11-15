// ex2.cpp - Calculates the factorial of 100!.
#include <iostream>
#include <array>

int main()
{
	const int arrSize = 100;

	std::array<long double, arrSize> factorialArr;

	factorialArr[1] = factorialArr[0] = 1LL;
	for (int i = 2; i < arrSize; i++) {
		factorialArr[i] = i * factorialArr[i-1];
	}
	for (int i = 0; i < arrSize; i++) {
		std::cout << 
			std::fixed << i << "! = " << factorialArr[i]
		<< std::endl;
	}
}
