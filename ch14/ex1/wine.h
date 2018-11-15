#include <string>
#include <iostream>
#include <valarray>
typedef std::valarray<int> ArrayInt;

template<typename T1, typename T2>
class Pair
{
private:
    T1 years;
    T2 bottles;
public:
    Pair(const int y, const int yr[], const int bt[])
	:years(yr, y), bottles(bt, y){}
    Pair(const int y)
	:years(y), bottles(y){}
    void show(const int i) const;
    int sum() const { return bottles.sum(); }
    void setYear(const int i, const int yr) { years[i] = yr; }
    void setBottle(const int i, const int bt) { bottles[i] = bt; }
};

class Wine
{
private:
    typedef Pair<ArrayInt, ArrayInt> PairArr;
    std::string label;
    const int ARR_SIZE;
    PairArr YearAndBottle;
public:
    Wine(const char * l, const int y, const int yr[], const int bt[])
	: label(l), ARR_SIZE(y), YearAndBottle(y, yr, bt){}
    Wine(const char * l, const int y) 
	: label(l), ARR_SIZE(y), YearAndBottle(y){}

    std::string & Label() { return label; }
    int sum() { return YearAndBottle.sum();}
    void getBottles();
    void show() const;
};
