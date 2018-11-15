// ex5.cpp
#include <iostream>

double getTaxOwed(double dincome);

int main()
{
    double dincome;
    std::cout << "Enter your income to calculate the tax" << std::endl;
    std::cin >> dincome;

    while (dincome)
    {
	std::cout << "You owe " << getTaxOwed(dincome) << " tvarps in tax\n" << std::endl;
	std::cout << "Enter another income" << std::endl;
	std::cin >> dincome;
    }
}

double getTaxOwed(double dincome)
{
    double dtaxOwed = 0;

    if (dincome <= 5000)
    {
	dtaxOwed = 0;
    }
    else if (dincome > 5000 && dincome <= 15000)
    {
	dincome -= 5000;
	dtaxOwed = dincome * 0.1;
    }
    else if (dincome > 10000 && dincome <= 35000)
    {
	dincome -= 15000;
	dtaxOwed += (10000 * 0.1) + dincome * 0.15;
    }
    else
    {
	dincome -= 35000;
	dtaxOwed += (10000 * 0.1) + (20000 * 0.15) + dincome * 0.2;
    }
    return dtaxOwed;
}
