#include "Cd.h"
#include <iostream>
#include <cstring>

Cd::Cd(const char * s1, const char * s2, const int n, const double x)
{
    performers = new char[strlen(s1)];
    std::strcpy(performers, s1);
    lable = new char[strlen(s2)];
    std::strcpy(lable, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    performers = new char[strlen(d.performers)];
    std::strcpy(performers, d.performers);
    lable = new char[strlen(d.lable)];
    std::strcpy(lable, d.lable);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers = new char[1];
    performers[0] = '\0';
    lable = new char[1];
    lable[0] = '\0';
    selections = 0;
    playtime = 0;
}

Cd::~Cd()
{
    delete [] performers;
    delete [] lable;
}

void Cd::Report() const
{
    using std::cout;
    cout << "\"" << lable << "\"" << " by " <<
	"\"" << performers << "\"\n" << "Selections: " << 
	selections << "\nPlaytime: " << playtime << '\n';
}

Cd & Cd::operator=(const Cd & d)
{
    std::strcpy(performers, d.performers);
    std::strcpy(lable, d.lable);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
