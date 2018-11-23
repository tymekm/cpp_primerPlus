#include "Employee.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <memory>
#include <iomanip>
#include <cstring>
#include <typeinfo>

typedef std::unique_ptr<abstr_emp> emplP;
typedef std::vector<emplP> emplArr;
const int MAX = 10;
enum employees {employee, manager, fink, highfink};

inline void eatline() { while (std::cin.get() != '\n') continue; }
void options();
void showArr(const emplArr & arr);
void addEmpl(const int empl, emplArr & arr);
void delEmpl(emplArr & arr);
void write(const emplArr & arr);
emplArr & read(emplArr & arr);

int main()
{
    using std::cout;
    using std::cin;

    emplArr myEmpl(0);
    char ch;
    options();
    while (cin >> ch && ch != 'q')
    {
        while (strchr("rqswemfhdH", ch) == NULL)
        {
            cout << "Please enter a valid option\n";
	    options();
            cin >> ch;
        }

	switch (ch) 
	{
	    case 's':
		eatline();
		showArr(myEmpl);		
		break;
	    case 'w':
		eatline();
		write(myEmpl);
		break;
	    case 'r':
		eatline();
		read(myEmpl);
		break;
	    case 'e':
		eatline();
		addEmpl(employee, myEmpl);
		break;
	    case 'm':
		eatline();
		addEmpl(manager, myEmpl);
		break;
	    case 'f':
		eatline();
		addEmpl(fink, myEmpl);
		break;
	    case 'h':
		eatline();
		addEmpl(highfink, myEmpl);
		break;
	    case 'd':
		eatline();
		delEmpl(myEmpl);
		break;
	    case 'H':
		eatline();
		options();
		break;
	    case 'q':
		return 0;
	}
    }
    return 0;
}

void options()
{
    using std::cout;
    using std::setw;
    cout << "Choose a option\n";
    cout << std::left;
    cout << setw(30) << "r: Read from file"; 
    cout << "w: Write to file"<< '\n';
    cout << setw(30) << "e: Add employee";
    cout << "m: Add Manager" << '\n';
    cout << setw(30)  << "f: Add Fink"; 
    cout << "h: Add Highfink" << '\n';
    cout <<  setw(30) << "s: Show employees"; 
    cout << "d: Delete employee" << '\n';
    cout <<  setw(30) << "H: Show these options"; 
    cout <<  "q: Quit" << '\n';
}

void showArr(const emplArr & arr)
{
    using std::cout;
    if (arr.empty())
	cout << "No employees on record.\n";
    else
    {
	int size = arr.size();
	for (int i = 0; i < size; i++) 
	{
	    cout << i << ": ";
	    arr[i]->ShowAll();
	}
    }
}

void addEmpl(const int empl, emplArr & arr)
{
    using std::cout;
    if (arr.size() == MAX)
	cout << "Employee list already full full\n";
    else
    {
	switch (empl) 
	{
	    case employee:
		{
		    emplP temp(new Employee);
		    temp->SetAll();
		    arr.push_back(std::move(temp));
		}
		break;
	    case manager:
		{
		    emplP temp(new Manager);
		    temp->SetAll();
		    arr.push_back(std::move(temp));
		}
		break;
	    case fink:
		{
		    emplP temp(new Fink);
		    temp->SetAll();
		    arr.push_back(std::move(temp));
		}
		break;
	    case highfink:
		{
		    emplP temp(new HighFink);
		    temp->SetAll();
		    arr.push_back(std::move(temp));
		}
		break;
	}
	cout << "Employee added successfully\n";
    }
}

void delEmpl(emplArr & arr)
{
    using std::cout;
    using std::cin;
    if (arr.empty())
         cout << "Employee list already empty.\n";
    else
    {
	showArr(arr);    
	cout << "Which index to delete?: ";
	unsigned int toDel;
	cin >> toDel;
	if (toDel > arr.size())
	    cout << "Value out of bounds!\n";
	else
	{
	    arr.erase(arr.begin() + toDel);
	    cout << "Index " << toDel << " deleted\n";
	}
    }
}

void write(const emplArr & arr)
{
    using std::cout;
    if (arr.empty())
	cout << "No employees on record to write.\n";
    else
    {
	cout << "Enter file name: ";
	std::string fname;
	std::cin >> fname;
	std::ofstream fout(fname);

	int size = arr.size();
	for (int i = 0; i < size; i++) 
	{
	    if (typeid(Employee) == typeid(*arr[i]))
		fout << employee << ' ';
	    else if (typeid(Manager) == typeid(*arr[i]))
		fout << manager << ' ';
	    else if (typeid(Fink) == typeid(*arr[i]))
		fout << fink << ' ';
	    else if (typeid(HighFink) == typeid(*arr[i]))
		fout << highfink << ' ';
	    arr[i]->writeall(fout);
	    fout << '\n';
	}
	cout << "Successfully written to " << fname;
    }
}

emplArr & read(emplArr & arr)
{
    std::cout << "Enter file to open: ";
    std::string fname;
    std::cin >> fname;
    std::ifstream fin(fname);

    if (!fin.is_open())
    {
	std::cout << "Could not open " << fname << " file.\n";
	return arr;
    }

    arr.clear();
    int type;
    
    while (!fin.eof())
    {
	fin >> type;
        if (type == employee)
        {	
            std::string fname, lname, job;
            fin >> fname;
            fin >> lname;
            fin >> job;
            emplP temp(new Employee(fname, lname, job));
            arr.push_back(std::move(temp));
        }

        else if (type == manager)
        {
            std::string fname, lname, job;
            int inchargeof;
            fin >> fname;
            fin >> lname;
            fin >> job;
            fin >> inchargeof;
            emplP temp(new Manager(fname, lname, job, inchargeof));
            arr.push_back(std::move(temp));
        }

        else if (type == fink)
        {
            std::string fname, lname, job, reportsto;
            fin >> fname;
            fin >> lname;
            fin >> job;
            fin >> reportsto;
            emplP temp(new Fink(fname, lname, job, reportsto));
            arr.push_back(std::move(temp));
        }

        else if (type == highfink)
        {
            std::string fname, lname, job, reportsto;
            int inchargeof;
            fin >> fname;
            fin >> lname;
            fin >> job;
	    fin >> inchargeof;
            fin >> reportsto;
            emplP temp(new HighFink(fname, lname, job,
        		inchargeof, reportsto));
            arr.push_back(std::move(temp));
        }
	type = -1;
    }
    std::cout << "File read in successfully.\n";
    return arr;
}
