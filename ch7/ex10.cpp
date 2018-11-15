// ex10.cpp
#include <iostream>

double calculate(double a, double b, double (*pf)(double a, double b));
double add(double a, double b);
double reduce(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

int main()
{
    double a;
    double b;
    char sign;
    double result;
    while (std::cin)
	{
	    std::cout << "Enter two numbers: \n";
	    std::cin >> a;
	    std::cin >> b;
	    std::cout << "Enter arithmatic operator to use: \n";
	    std::cin >> sign;
	    if (sign != '+' && sign != '-' && sign != '*' && sign != '/')
	    {
		std::cout << "Not a valid operator...\n";
		continue;
	    }
	    switch (sign)
	    {
		case '+':
		    result = calculate(a, b, add);
		    break;
		case '-':
		    result = calculate(a, b, reduce);
		    break;
		case '*':
		    result = calculate(a, b, multiply);
		    break;
		case '/':
		    result = calculate(a, b, divide);
		    break;
	    }
	    std::cout << result << '\n';
	}
    std::cout << "None numeric character entered, aborting...\n";
}

double calculate(double a, double b, double (*pf)(double a, double b))
{
    return pf(a,b);
}

double add(double a, double b)
{
    return a + b;
}

double reduce(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}
