#include "Employee.h"
#include <iostream>
#include <fstream>

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

std::ofstream & abstr_emp::wData(std::ofstream & os) const
{
    os << fname << " " << lname << ' ' << job;  
    return os;
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

void abstr_emp::writeall(std::ofstream & os)
{
    wData(os);
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
std::ofstream & Employee::wData(std::ofstream & os) const
{
    return os;
}

void Employee::SetAll()
{
    abstr_emp::Get();
}

void Employee::writeall(std::ofstream & os)
{
    abstr_emp::wData(os);
}


// -----------------------------------------------------------------------
// 	Manager 
// -----------------------------------------------------------------------

void Manager::Data() const
{
    cout << "   In charge of " << inchargeof << " employees\n";
}

std::ofstream & Manager::wData(std::ofstream & os) const
{
    os << " " << inchargeof;
    return os;
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

void Manager::writeall(std::ofstream & os)
{
    abstr_emp::wData(os);
    wData(os);
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

std::ofstream & Fink::wData(std::ofstream & os) const
{
    os << " " << reportsto;
    return os;
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

void Fink::writeall(std::ofstream & os)
{
    abstr_emp::wData(os);
    wData(os);
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

std::ofstream & HighFink::wData(std::ofstream & os) const
{
    abstr_emp::wData(os);
    Manager::wData(os);
    Fink::wData(os);
    return os;
}

void HighFink::writeall(std::ofstream & os)
{
    wData(os);
}


void HighFink::SetAll()
{
    abstr_emp::Get();
    Manager::Get();
    Fink::Get();
}
