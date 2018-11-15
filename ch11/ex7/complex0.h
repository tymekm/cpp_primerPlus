#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex
{
private:
    int real;
    int imaginairy;

public:
    Complex();
    Complex(int a, int b);
    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend Complex operator-(const Complex& c1, const Complex& c2);
    friend Complex operator*(const Complex& c1, const Complex& c2);
    friend Complex operator*(int x, const Complex& c);
    friend Complex operator~(const Complex& c);
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);
};

#endif
