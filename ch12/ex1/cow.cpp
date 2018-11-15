#include "cow.h"
#include <iostream>
#include <cstring>

Cow::Cow()
{
    name[0] = '\0';
    hobby = new char[1];
    hobby = nullptr;
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    using std::strcpy;
    using std::strlen;
    std::strcpy(name, nm);
    hobby  = new char [std::strlen(ho + 1)];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow& c)
{
    strcpy(name, c.name);
    int length = strlen(c.hobby);
    hobby = new char[length + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
}

Cow::~Cow()
{
    delete hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    using std::strcpy;
    using std::strlen;

    strcpy(name, c.name);
    delete [] hobby;
    int length = strlen(c.hobby);
    hobby = new char[length + 1];
    strcpy(hobby, c.hobby);
    weight = c.weight;
    return *this;
}

void Cow::showCow() const
{
    using std::cout;
    cout << "Name: " << name << "\nHobby: " << hobby << "\nWeight: " 
	<< weight << " pounds\n";
}
