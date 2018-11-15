// ex6.cpp
#include <iostream>

struct donations
{
    std::string sdonor;
    double damountDonated;
};

int main()
{
    int narrSize;
    std::cout << "How many contributions would you like to enter" << std::endl;
    std::cin >> narrSize;
    donations * donor = new donations [narrSize];

    for (int i = 0; i < narrSize; i++) 
    {
        std::cout << "Name donor: ";
	std::cin >> donor[i].sdonor;
	std::cout << "Amount donated: ";
	std::cin >> donor[i].damountDonated;
    }

    bool bgrandPatrons = false;
    bool bpatrons = false;

    for (int i = 0; i < narrSize; i++) 
    {
        if (donor[i].damountDonated >= 10000)
	    bgrandPatrons = true;
	else if (donor[i].damountDonated < 10000)
	    bpatrons = true;
    }

    if (bgrandPatrons)
    {
	std::cout << "Grand Patrons" << std::endl;

	for (int i = 0; i < narrSize; i++) 
	{
	    if (donor[i].damountDonated >= 10000)
	    {
		std::cout << donor[i].sdonor << std::endl;
		std::cout << donor[i].damountDonated << "\n" << std::endl;
	    }
	}
    }
	
    if (bpatrons)
    {
	std::cout << "Patrons" << std::endl;

	for (int i = 0; i < narrSize; i++) 
	{
	    if (donor[i].damountDonated < 10000)
	    {
		std::cout << donor[i].sdonor << std::endl;
		std::cout << donor[i].damountDonated << "\n" << std::endl;
	    }
	}
    }
    delete [] donor;
}

