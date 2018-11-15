// ex8.cpp
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream inFile;
    inFile.open("hello.txt");
    std::string sline;
    int ncount = 0;

    if (inFile.is_open())
    {
	while(getline(inFile, sline))
	    ncount += sline.length();
    }
    inFile.close();
    std::cout << ncount << " in file" << std::endl;
}

