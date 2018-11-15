#include "complex0.h"
#include <iostream>

Complex::Complex()
{
}

Complex::Complex(int a, int b)
{
    real = a;
    imaginairy = b;
}

Complex operator+(const Complex& c1, const Complex& c2)
{
    Complex newC;
    newC.real = c1.real + c2.real;
    newC.imaginairy = c1.imaginairy + c2.imaginairy;
    return newC;
}

Complex operator-(const Complex& c1, const Complex& c2)
{
    Complex newC;
    newC.real = c1.real - c2.real;
    newC.imaginairy = c1.imaginairy - c2.imaginairy;
    return newC;
}

Complex operator*(const Complex& c1, const Complex& c2)
{
    Complex newC;
    newC.real = c1.real * c2.real - c1.imaginairy * c2.imaginairy;
    newC.imaginairy = c1.real * c2.imaginairy + c1.imaginairy * c2.real;
    return newC;
}

Complex operator*(int x, const Complex& c)
{
    Complex newC;
    newC.real = x * c.real;
    newC.imaginairy = x * c.imaginairy;
    return newC;
}

Complex operator~(const Complex& c)
{
    Complex newC;
    newC.real = c.real;
    newC.imaginairy = -c.imaginairy;
    return newC;
}

std::ostream& operator<<(std::ostream& os, const Complex& c)
{
    os << '(' << c.real << ", " << c.imaginairy << 'i' << ')';
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c)
{
    using std::cout;
    using std::cin;
    cout << "real: ";
    is >> c.real;
    if (!cin)
    {
	cout << "Not a number, aborting.\n";
	return is;
    }
    cout << "imaginairy: ";
    is >> c.imaginairy;
    if (!cin)
    {
	cout << "Not a number, aborting.\n";
	return is;
    }
    return is;
}
