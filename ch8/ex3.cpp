// ex3.cpp
#include <iostream>
#include <string>
#include <cctype>

std::string uppercase(std::string & str);

int main()
{
    std::string str;
    while (1)
    {
	std::cout << "\nEnter string to uppercase (q to quit)\n";
	getline(std::cin, str);
	if (str == "q" || str == "Q")
	{
	    std::cout << "Done\n";
	    break;
	}
	std::cout << uppercase(str);
    }
}

std::string uppercase(std::string & str)
{
    std::string temp;
    for (int i = 0; i < str.length(); i++) 
    {
	
        temp += toupper(str[i]);
    }
    return temp;
}
