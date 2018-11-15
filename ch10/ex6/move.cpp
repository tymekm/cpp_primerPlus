#include "move.h"
#include <iostream>


Move::Move(double a, double b)
{
    x = a;
    y = b;
}

void Move::showMove() const
{
    using std::cout;
    cout << "X = " << x << ", Y = " << y << '\n';
}

Move Move::add(const Move& m) const
{
    double newX = x + m.x;
    double newY = y + m.y;
    Move newMove {newX, newY};
    return newMove;
}

void Move::reset(double a, double b)
{
    x = a;
    y = b;
}
