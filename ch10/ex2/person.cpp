#include <iostream>
#include "person.h"

Person::Person(const string & ln, const char * fn)
{
    Person::lname = ln;

    int fnLength = (sizeof(fn)/sizeof(*fn));
    for (int i = 0; i < fnLength -1; i++) 
    {
	Person::fname[i] = fn[i];
    }
}

void Person::show() const
{
    using std::cout;
    if (Person::fname[0] != '\0' || Person::lname != "")
    {
	cout << "\"" << Person::lname; 
	if (Person::fname[0] != '\0' && Person::lname != "")
	    cout << ", ";
	cout << Person::fname << "\"\n";
    }
    else
	cout << "no name found\n";
}

void Person::formalShow() const
{
    using std::cout;
    if (Person::fname[0] != '\0' || Person::lname != "")
    {
	cout << "\"" << "Sir " << Person::lname;
	if (Person::fname[0] != '\0' && Person::lname != "")
	    cout << ", " ;
	cout << Person::fname << "\"\n";
    }
    else
	cout << "no name found\n";
}
