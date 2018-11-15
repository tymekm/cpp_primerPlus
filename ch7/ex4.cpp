// ex4.cpp
#include <iostream>

long long unsigned getProbability(unsigned nnumber, unsigned npick, unsigned mnumber);

int main()
{
    unsigned nnumber, npick, mnumber;
    std::cout << "Enter number of possible number:" << std::endl;
    std::cin >> nnumber;
    std::cout << "Enter number of needed hits::" << std::endl;
    std::cin >> npick;
    std::cout << "Enter number the mega number:" << std::endl;
    std::cin >> mnumber;

    std::cout << "Your chances of winning are 1 in " << getProbability(nnumber, npick, mnumber) << std::endl;
}

long long unsigned getProbability(unsigned nnumber, unsigned npick, unsigned mnumber)
{
    long double winningChance;

    long double nchance = 1;
    for (unsigned n = nnumber, p = npick; p > 0;n--, p--) 
    {
       nchance *= n/p;
    }

    winningChance = nchance * mnumber;

    return winningChance;
}
