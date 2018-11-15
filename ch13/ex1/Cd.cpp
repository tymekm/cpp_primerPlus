#include "Cd.h"
#include <iostream>
#include <cstring>

Cd::Cd(const char * s1, const char * s2, const int n, const double x)
{
    std::strcpy(performers, s1);
    std::strcpy(lable, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d)
{
    std::strcpy(performers, d.performers);
    std::strcpy(lable, d.lable);
    selections = d.selections;
    playtime = d.playtime;
}

Cd::Cd()
{
    performers[0] = '\0';
    lable[0] = '\0';
    selections = 0;
    playtime = 0;
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
