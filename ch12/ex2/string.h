#ifndef STRING_H
#define STRING_H
#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;

class String
{
private:
    char * str;
    int len;
    static int num_strings;
    static const int CINLIM = 80;
public:
    String();
    String(const char * s);
    String(const String &);
    ~String();
    int length() const {return len;}
    void stringLow();
    void stringUp();
    int countChar(const char & c);

    String & operator=(const String&);
    String & operator=(const char * s);
    char & operator[](int i);
    const char & operator[](int i) const;

    friend String operator+(const String & s1, const String & s2);
    friend bool operator<(const String & s1, const String & s2);
    friend bool operator>(const String & s1, const String & s2);
    friend bool operator==(const String & s1, const String & s2);
    friend ostream & operator<<(ostream & os, const String & s);
    friend istream & operator>>(istream & is, String & s);

    static int HowMany();
};

#endif
