#include "port.h"
#include <cstring>

using std::strlen;
using std::strcpy;

//-------------------------------------------------------------
// Port
//-------------------------------------------------------------

Port::Port(const char * br, const char * st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port & p)
{
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if (this == &p)
	return *this;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

void Port::show() const
{
    std::cout << "Brand: " << brand << 
	"\nKind: " << style << "\nBottles: " << bottles << '\n';
}

ostream & operator<<(ostream & os, const Port & p)
{
    std::cout << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

//-------------------------------------------------------------
// VintagePort
//-------------------------------------------------------------


VintagePort::VintagePort()
{
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
    : Port(br, "Vintage", b)
{
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp)
{
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == &vp)
	return *this;
    nickname = new char[strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::show() const
{
    Port::show();
    std::cout << "Nickname: " << nickname << "\nYear: " << year << '\n';
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    std::cout << vp.nickname << ", " << vp.year;
    return os;
}

