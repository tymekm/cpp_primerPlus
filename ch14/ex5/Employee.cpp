#include "Employee.h"
#include <iostream>

using std::cout;
using std::cin;

// -----------------------------------------------------------------------
// 	abstr_emp 
// -----------------------------------------------------------------------

abstr_emp::~abstr_emp() {}

void abstr_emp::Data() const
{
    cout << fname << " " << lname << "\tJob: " << job << '\n';
}

void abstr_emp::Get()
{
    cout << "First name: ";
    getline(cin, fname);
    cout << "Last name: ";
    getline(cin, lname);
    cout << "Job: ";
    getline(cin, job);
}

void abstr_emp::ShowAll() const
{
    Data();
}

void abstr_emp::SetAll()
{
    Get();
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    cout << e.fname << " " << e.lname;
    return os;
}

// -----------------------------------------------------------------------
// 	Employee 
// -----------------------------------------------------------------------

void Employee::ShowAll() const
{
    abstr_emp::Data();
}

void Employee::SetAll()
{
    abstr_emp::Get();
}

// -----------------------------------------------------------------------
// 	Manager 
// -----------------------------------------------------------------------

void Manager::Data() const
{
    cout << "In charge of " << inchargeof << " employees\n";
}

void Manager::Get()
{
    cout << "Enter amount of personel under him: ";
    cin >> inchargeof;
    while (cin.get() != '\n')
	continue;
}

void Manager::ShowAll() const
{
    abstr_emp::Data();
    Data();
}

void Manager::SetAll()
{
    abstr_emp::Get();
    Get();
}

// -----------------------------------------------------------------------
// 	Fink 
// -----------------------------------------------------------------------
void Fink::Data() const
{
    cout << "Reports to " << reportsto << '\n';
}

void Fink::Get()
{
    cout << "Enter name supervisor: ";
    getline(cin, reportsto);
}

void Fink::ShowAll() const
{
    abstr_emp::Data();
    Data();
}

void Fink::SetAll()
{
    abstr_emp::Get();
    Get();
}

// -----------------------------------------------------------------------
// 	HighFink 
// -----------------------------------------------------------------------

void HighFink::ShowAll() const
{
    abstr_emp::Data();
    Manager::Data();
    Fink::Data();
}

void HighFink::SetAll()
{
    abstr_emp::Get();
    Manager::Get();
    Fink::Get();
}
