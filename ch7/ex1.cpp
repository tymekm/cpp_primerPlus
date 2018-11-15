// ex1.cpp
#include <iostream>

double harmonicMean(int x, int y);

int main()
{
    int x,y;
    while (x&&y)
    {
	std::cout << "Enter two values:" << std::endl;
	std::cin >> x;
	std::cin >> y;
	std::cout << harmonicMean(x,y) << std::endl;
    }
}

double harmonicMean(int x, int y)
{
    return (2 * x * y / (x + y));
}
