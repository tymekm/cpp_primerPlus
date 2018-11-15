// ex10.cpp
#include <iostream>

int main()
{
	int times;
	std::cout << "Enter a number: __\b\b";
	std::cin >> times;

	int asterisc = 1;
	int dot = times -1;
	for (int i = 0; i < times; i++) 
	{
		for (int j = 0; j < dot; j++) 
		{
			std::cout << ".";
		}	
		for (int j = 0; j < asterisc; j++) 
		{
			std::cout << "*";
		}	
		std::cout << "\n";
		
		asterisc++;
		dot--;
	}
}
