// ex1.cpp
#include <iostream>
#include <string>

void print(std::string str);
void print(std::string str, int n);

int counter;

int main()
{
    for (int i = 0; i < 5; i++) 
    {
	print("hello world");
    }

    if (counter > 0)
	print("Hello there", counter);

    return 0;
}

void print(std::string str)
{
    counter ++;    
    std::cout << str << '\n';
}

void print(std::string str, int n)
{
    for (int i = 0; i < n; i++) 
	std::cout << str << '\n';
}
