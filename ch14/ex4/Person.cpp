#include "Person.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::cin;

// -----------------------------------------------------------------------
// 	Person 
// -----------------------------------------------------------------------

Person::~Person() {}

void Person::Data() const
{
    cout << lastName << ", " << firstName << '\n';
}

void Person::Get()
{
    cout << "Enter first name: ";
    getline(cin, firstName);
    cout << "Enter last name: ";
    getline(cin, lastName);
}

// -----------------------------------------------------------------------
// 	Gunslinger 
// -----------------------------------------------------------------------

void Gunslinger::Data() const
{
    cout << "Draw time: " << drawTime << "\nNothes: " << nothes << '\n';
}

void Gunslinger::Get()
{
    cout << "Enter draw time: ";
    cin >> drawTime;
    while (cin.get() != '\n')
	continue;
    cout << "Enter amount of nothes on the gun: ";
    cin >> nothes;
    while (cin.get() != '\n')
	continue;
}

void Gunslinger::Set()
{
    cout << "Gunslinger\n";
    Person::Get();
    Get();
}

void Gunslinger::Show() const
{
    cout << "Gunslinger:\n";
    Person::Data();
    Data();
}

// -----------------------------------------------------------------------
// 	PokerPlayer 
// -----------------------------------------------------------------------

void PokerPlayer::Set()
{
    cout << "PokerPlayer\n";
    Person::Get();
}

void PokerPlayer::Show() const
{
    cout << "PokerPlayer:\n";
    Person::Data();
    cout << Draw() << " is the card drawn\n";
}

int PokerPlayer::Draw() const
{
    std::srand(std::time(0));
    return rand() % 52 + 1;
}

// -----------------------------------------------------------------------
// 	BadDude 
// -----------------------------------------------------------------------

void BadDude::Data() const
{
    cout << cDraw() << " is the card drawn\n";
}

void BadDude::Set()
{
    Person::Get();
    Gunslinger::Get();
}

void BadDude::Show() const 
{
    Person::Data();
    Gunslinger::Data();
    Data();
}

double BadDude::gDraw() const
{
    return Gunslinger::Draw(); 
}

int BadDude::cDraw() const
{
    return PokerPlayer::Draw();
}
