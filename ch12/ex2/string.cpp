#include "string.h"
#include <cstring>
#include <cctype>
using std::strcpy;
using std::strlen;
using std::strcmp;

int String::num_strings = 0;

int String::HowMany()
{
    return num_strings;
}

String::String(const char * s)
{
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    num_strings++;
}

String::String()
{
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String & s)
{
    num_strings++;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
}

String::~String()
{
    --num_strings;
    delete [] str;
}

void String::stringLow()
{
    for (int i = 0; i < len; i++) 
    {
	str[i] = tolower(str[i]);     
    }
}

void String::stringUp()
{
    for (int i = 0; i < len; i++) 
    {
	str[i] = toupper(str[i]);     
    }
}

int String::countChar(const char & c)
{
    int count;
    for (int i = 0; i < len; i++) 
    {
	if (str[i] == c)
	    count++;
    }
    return count;
}


String & String::operator=(const String & s)
{
    if (this == &s)
	return *this;
    delete [] str;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

const char & String::operator[](int i) const
{
    return str[i];
}

String operator+(const String & s1, const String & s2)
{
    using std::strcat;
    String temp;
    temp.len = s1.len + s2.len;
    temp.str = new char[temp.len + 1]; 
    strcat(temp.str, s1.str);
    strcat(temp.str, s2.str);
    return temp;
}

bool operator<(const String & s1, const String & s2)
{
    return (strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String & s1, const String & s2)
{
    return s1 < s2;
}

bool operator==(const String & s1, const String & s2)
{
    return (strcmp(s1.str, s2.str) == 0);
}

ostream & operator<<(ostream & os, const String & s)
{
    os << s.str;
    return os;
}

istream & operator>>(istream & is, String & s)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
	s = temp;
    while (is && is.get() != '\n')
	continue;
    return is;
}
