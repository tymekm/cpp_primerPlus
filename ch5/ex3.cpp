// ex3.cpp - Accepts numbers nad diplays the sum of it and all previus numbers.
#include <iostream>
#include <array>

int main()
{
	int num;
	int sum = 0;

	std::cout << "Enter any number" << std::endl;

	while(num)
	{
		std::cin >> num;
		sum += num;
		std::cout << "The sum is = " << sum << std::endl;
	}
}
