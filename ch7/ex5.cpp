// ex5.cpp
#include <iostream>

long long unsigned getFactorial(long long unsigned n);

int main()
{
    long long unsigned n = 1;
    while (std::cin)
    {
	std::cout << "Enter number to factorialize: \n"; 
	std::cin >> n;
	std::cout << getFactorial(n) << std::endl;
    }
}

long long unsigned getFactorial(long long unsigned n)
{
    if (n == 1 || n == 0)
    {
	return 1;
    }
    else
    {
	return n * getFactorial(n-1);
    }
}
