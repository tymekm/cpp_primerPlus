#include "Worker.h"
#include <iostream>
using std::cout;
using std::cin;

// -----------------------------------------------------------------------
// 	Worker 
// -----------------------------------------------------------------------

Worker::~Worker(){}

void Worker::data() const
{
    cout << "Name: " << fullName << '\n';
    cout << "Employee ID: " << id << '\n';
}

void Worker::get()
{
    getline(cin, fullName);
    cout << "Enter worker's ID: ";
    cin >> id;
    while (cin.get() != '\n')
	continue;
}

// -----------------------------------------------------------------------
// 	Waiter 
// -----------------------------------------------------------------------

void Waiter::set()
{
    cout << "Enter waiter's name: ";
    Worker::get();
    get();
}

void Waiter::show() const
{
    cout << "Category: Waiter'\n";
    Worker::data();
    data();
}

void Waiter::data() const
{
    cout << "Panache rating: " << panache << '\n';
}

void Waiter::get()
{
    cout << "Enter Waiter's panache rating: ";
    cin >> panache;
    while (cin.get() != '\n')
	continue;
}

// -----------------------------------------------------------------------
// 	Singer 
// -----------------------------------------------------------------------

const char * Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::set()
{
    cout << "Enter singer's name: ";
    Worker::get();
    get();
}

void Singer::show() const
{
    cout << "Category: Singer\n";
    Worker::data();
    data();
}

void Singer::data() const
{
    cout << "Vocal ranger: " << pv[voice] << '\n';
}

void Singer::get()
{
    cout << "Enter number for singer's vocal ranger:\n";
    int i;
    for (i = 0; i < Vtypes; i++) 
    {
	cout << i << ": " << pv[i] << "   ";
	if (i % 4 == 3)
	    cout << '\n';
    }
    if (i % 4 != 0)
	cout << '\n';
    cin >> voice;
    while (cin.get() != '\n')
	continue;
}

// -----------------------------------------------------------------------
// 	SingerWaiter 
// -----------------------------------------------------------------------

void SingerWaiter::data() const 
{
    Singer::data();
    Waiter::data();
}

void SingerWaiter::get()
{
    Singer::get();
    Waiter::get();
}

void SingerWaiter::set()
{
    cout << "Enter singing waiter's name: ";
    Worker::get();
    get();
}

void SingerWaiter::show() const
{
    cout << "Category: singing waiter\n";
    Worker::data();
    data();
}
