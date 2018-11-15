// ex4.cpp
#include <iostream>
#include <string>

struct stringy
{
    std::string str;
    int ct;
};

void set(stringy & someStringy, std::string str);
void show(const stringy & someStringy, int n = 1);
void show(const std::string str, int n = 1);
// prototypes

int main()
{
    stringy breany;
    std::string testing = "Reality isn't what it used to be.";

    set(breany, testing);

    show(breany);
    show(breany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("Done!");
    return 0;
}

void set(stringy & someStringy, std::string str)
{
    someStringy.str = str;
    someStringy.ct = str.length();
}

void show(const std::string str, int n)
{
    for (int i = 0; i < n; i++) 
    {
        std::cout << str << "\n";
    }
}

void show(const stringy & someStringy, int n)
{
    for (int i = 0; i < n; i++) 
    {
	std::cout << someStringy.str << "\n";    
    }
}
