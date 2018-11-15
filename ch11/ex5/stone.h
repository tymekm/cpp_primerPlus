#ifndef STONE_H
#define STONE_H
#include <iostream>

class Stone
{
private:
    enum {Lbs_per_stn = 14};
    enum Mode {int_stone, int_pounds, flaot_pounds};
    Mode mode;
    int stone;
    double pounds;
    double pounds_left;

public:
    Stone(int weight, int form);
    Stone(float lbs);
    Stone();
    ~Stone();
    void setMode(int form);
    friend Stone operator+(const Stone& s1, const Stone&s2);
    friend Stone operator-(const Stone& s1, const Stone&s2);
    friend Stone operator*(const Stone& s1, const Stone&s2);
    friend std::ostream& operator<<(std::ostream& os, const Stone& s);
};
#endif
