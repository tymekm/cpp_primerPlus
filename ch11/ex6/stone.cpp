#include "stone.h"
#include <iostream>

using std::cout;

Stone::Stone(int weight, int form)
{
    setMode(form); 

    if (mode == int_stone)
	stone =  weight;
    else if (mode == int_pounds)
    {
	stone = weight / Lbs_per_stn;
	pounds_left = weight % Lbs_per_stn;
	pounds = weight;
    }
}

void Stone::setValues(int weight, int form)
{
        setMode(form); 

    if (mode == int_stone)
	stone =  weight;
    else if (mode == int_pounds)
    {
	stone = weight / Lbs_per_stn;
	pounds_left = weight % Lbs_per_stn;
	pounds = weight;
    }
}

Stone::Stone()
{
    stone = pounds = pounds_left = 0;
    mode = int_pounds;
}

Stone::~Stone()
{
}

void Stone::setMode(int form)
{
    switch (form) {
        case 0:
	    mode = int_stone;	
	    break;
        case 1:
	    mode = int_pounds;	
	    break;
    }
}

Stone operator+(const Stone& s1, const Stone&s2)
{
    Stone sum;
    sum.stone = s1.stone + s2.stone;
    sum.pounds_left = s1.pounds_left + s2.pounds_left;
    sum.pounds = s1.pounds + s2.pounds;
    return sum;
}

Stone operator-(const Stone& s1, const Stone& s2)
{
    Stone diff;
    diff.stone = s1.stone - s2.stone;
    diff.pounds_left = s1.pounds_left - s2.pounds_left;
    diff.pounds = s1.pounds - s2.pounds;
    return diff;
}

Stone operator*(const Stone& s1, const Stone& s2)
{
    Stone prod;
    prod.stone = s1.stone * s2.stone;
    prod.pounds_left = s1.pounds_left * s2.pounds_left;
    prod.pounds = s1.pounds * s2.pounds;
    return prod;
}

bool operator==(const Stone& s1, const Stone& s2)
{
    return s1.pounds == s2.pounds;
}

bool operator!=(const Stone& s1, const Stone& s2)
{
    return s1.pounds != s2.pounds;
}

bool operator<(const Stone& s1, const Stone& s2)
{
    return s1.pounds < s2.pounds;
}

bool operator>(const Stone& s1, const Stone& s2)
{
    return s1.pounds > s2.pounds;
}

bool operator<=(const Stone& s1, const Stone& s2)
{
    return s1.pounds <= s2.pounds;
}

bool operator>=(const Stone& s1, const Stone& s2)
{
    return s1.pounds >= s2.pounds;
}

std::ostream& operator<<(std::ostream& os, const Stone& s)
{
    if (s.mode == s.int_stone)
	os << s.stone << " stones\n";
    else
	os << s.stone << " stones " << s.pounds_left << " pounds.\n";
    return os;
}
