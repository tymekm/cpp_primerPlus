// ex9.cpp
//
// UNFINISHED!
//
//
#include <iostream>
#include <fstream>
#include <string>

struct Contribution
{
    std::string sdonorName;
    double ddonation;
};

int main()
{
    std::ifstream inFile;
    inFile.open("donations.txt");
    int ncontributionNum = 0;
    Contribution * donors = new Contribution[ncontributionNum];
    int nlines = 0;

    if (inFile.is_open())
    {
	inFile >> ncontributionNum;

	std::string sline;
	while (getline(inFile, sline))
	{
	    nlines++;
	}

	//inFile.seekg(0, inFile.end);
	inFile.clear();
	std::cout << inFile.tellg() << std::endl;
	for (int i = 0; i < ncontributionNum; i++) 
	{
	    if (i)
	    {
		inFile >> donors[i].sdonorName;
		inFile >> donors[i].ddonation;
	    }
	}
    }
    inFile.close();

    std::cout << donors[0].sdonorName << std::endl;

    for (int i = 0; i < ncontributionNum; i++) 
    {
        std::cout << donors[i].sdonorName << std::endl;
    }
    delete [] donors;
}

