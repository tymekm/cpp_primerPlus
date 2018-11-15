#ifndef MEAN_H
#define MEAN_H
#include <stdexcept>
#include <iostream>
#include <string>

class bad_value : public std::logic_error
{
private:
    double x;
    double y;
public:
    explicit bad_value(const int a, const int b, const std::string & s)
	:x(a), y(b), logic_error(s) {}
    void report() const;
};

class bad_hmean : public bad_value
{
public:
    bad_hmean(const double a, const double b, const std::string & s)
	:bad_value(a,b,s) {}
    void report() const { bad_value::report(); };
};

class bad_gmean : public bad_value
{
public:
    bad_gmean(const double a, const double b, const std::string & s)
	:bad_value(a,b,s) {}
    void report() const { bad_value::report(); };
};

#endif

void bad_value::report() const
{
    std::cout << "Error, values used: " << x << ", " << y 
	<< " ; " << what() << '\n';
}
