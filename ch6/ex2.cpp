// ex2.cpp
#include <iostream>
#include <cctype>

int main()
{
    std::cout << "Enter numbers into the array" << std::endl;

    int SIZE = 10;
    double dnumArr[SIZE];
    double dsum = 0;
    int namount = 0;

    for (int i = 0; i < SIZE; i++) 
    {
	std::cin >> dnumArr[i];
	dsum += dnumArr[i];
	namount++;

	if (!std::cin.good())
	{
	    std::cout << "Not a number.\nAborting\n" << std::endl;
	    break;
	}
    } 
    double davr = dsum / namount;
    int nhigherThenAvr = 0;
    
    for (int i = 0; i < SIZE; i++) 
    {
	if (dnumArr[i] > davr)    
	{
	    nhigherThenAvr++;
	}
    }

    std::cout << "The average of the numbers is " << davr << std::endl;
    std::cout << nhigherThenAvr << " numbers were higher then average" << std::endl;
}
