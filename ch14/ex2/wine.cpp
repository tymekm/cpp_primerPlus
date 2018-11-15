#include "wine.h"
typedef std::valarray<int> ArrayInt;

template<>
void Pair<ArrayInt, ArrayInt>::show(const int i) const
{
    using std::cout;

	cout << '\t' << years[i] << "    " << bottles[i] << '\n';     
}

void Wine::getBottles()
{
    using std::cin;
    using std::cout;

    for (int i = 0; i < ARR_SIZE; i++) 
    {
	cout << "Enter #" << i + 1 << " year: ";
	int tempY;
	cin >> tempY;
	cout << "Enter amount of bottles: ";
	int tempB;
	cin >> tempB;
	PairArr::setYear(i, tempY);
	PairArr::setBottle(i, tempB);
    }
}

std::string & Wine::Label() const
{
    return ((std::string &)(*this));
}

void Wine::show() const
{
    using std::cout;
    cout << "Wine: " << Label() << '\n';
    cout << "\tYear  Bottles\n";
    for (int i = 0; i < ARR_SIZE; i++) 
    {
	PairArr::show(i);    
    }
    cout << '\n';
}
