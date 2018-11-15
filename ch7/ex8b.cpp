// ex8b.cpp
#include <iostream>
// constant data
const int Seasons = 4;
const char * Snames[Seasons] = {"Spring", "Summer", "Autumn", "Winter"};

struct doubleStruct  
{
    double expanses[Seasons];
};

void fill(doubleStruct * dsp);
void show(const doubleStruct * dsp);

int main()
{
    doubleStruct myExpanses;
    fill(&myExpanses);
    show(&myExpanses);
    return 0;
}

void fill(doubleStruct * dsp)
{
    for (int i = 0; i < Seasons; i++) 
    {
	std::cout << "Enter " << Snames[i] << " expenses: \n";    
	std::cin >> dsp->expanses[i];
    }
}

void show(const doubleStruct * dsp)
{
    double total = 0.0;
    std::cout << "\nExpanses\n";
    for (int i = 0; i < Seasons; i++) 
    {
	std::cout << Snames[i] << ": $" << dsp->expanses[i] << " ";    
	total += dsp->expanses[i];
    }
    std::cout << "Total expenses: $" << total << "\n";
}
