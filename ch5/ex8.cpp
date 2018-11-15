// ex8.cpp
#include <iostream>
#include <cstring>

int main()
{
	int arrSize;
	char * parray = new char[arrSize];
	int wordCount = -1;
	
	std::cout << "Enter wordds, enter \"done\" when you wish to quit" << std::endl;
	do
	{
		std::cin >> parray;
		wordCount++;

	}
	while(strcmp(parray, "done"));

	std::cout << "Total words entered: " << wordCount << std::endl;
}
