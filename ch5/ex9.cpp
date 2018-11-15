// ex9.cpp
#include <iostream>
#include <string>

int main()
{
	std::string word;
	int wordCount = -1;
	
	std::cout << "Enter wordds, enter \"done\" when you wish to quit" << std::endl;
	do
	{
		std::cin >> word;
		wordCount++;

	}
	while(word != "done");

	std::cout << "Total words entered: " << wordCount << std::endl;
}
