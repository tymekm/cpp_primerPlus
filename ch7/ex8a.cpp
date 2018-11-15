// ex8a.cpp
#include <iostream>
// constant data
const int Seasons = 4;
const char * Snames[Seasons] = {"Spring", "Summer", "Autumn", "Winter"};

void fill(double expenses[Seasons]);
void show(double da[Seasons]);

int main()
{
    double expenses[Seasons];
    fill(expenses);
    show(expenses);
    return 0;
}

void fill(double expenses[Seasons])
{
    for (int i = 0; i < Seasons; i++) 
    {
	std::cout << "Enter " << Snames[i] << " expenses: \n";    
	std::cin >> expenses[i];
    }
}

void show(double da[Seasons])
{
    double total = 0.0;
    std::cout << "\nExpanses\n";
    for (int i = 0; i < Seasons; i++) 
    {
	std::cout << Snames[i] << ": $" << da[i] << " ";    
	total += da[i];
    }
    std::cout << "Total expenses: $" << total << "\n";
}
