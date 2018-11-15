// ex1.cpp
#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string input;
    std::cout << "Enter some text" << std::endl;
    std::getline(std::cin, input)  ;

    for (int i = 0; i < input.length(); i++) 
    {
	if(islower(input[i]))
	{
	    input[i] = toupper(input[i]);
	}
	else if(isupper(input[i]))
	{
	    input[i] = tolower(input[i]);
	}
	else if (input[i] == '@')
	{
	    break;
	}
	std::cout << input[i];
    }
    std::cout << "\n";
}
