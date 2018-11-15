#include "Classic.h"
#include <iostream>
#include <cstring>


Classic::Classic(const char * s1, const char * s2, const char * s3, int n, double x)
    : Cd(s2, s3, n, x)
{
    primary = new char[strlen(s1)];
    std::strcpy(primary, s1);
}

Classic::Classic(const Classic & d)
    : Cd(d)
{
    primary = new char[strlen(d.primary)];
    std::strcpy(primary, d.primary);
}

Classic::Classic()
{
    primary = new char[1];
    primary[0] = '\0';
}

Classic::~Classic()
{
    delete [] primary;
}

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Primary number on track: " << primary << '\n';
}

Classic & Classic::operator=(const Classic & d)
{
    if (this == &d)
	return *this;
    Cd::operator=(d);
    strcpy(primary, d.primary);
    return *this;
}

