#include "stone.h"
#include <iostream>

enum Mode {int_stone, int_pounds, flaot_pounds};

int main()
{
    using std::cout;
    Stone stone1(500, int_pounds);    
    stone1.setMode(int_stone);
    cout << stone1;

    Stone stone2(777, int_pounds);

    Stone stone3;

    stone3 = stone1 + stone2;

    cout << stone3;
    stone2.setMode(int_stone);
    cout << stone2;


}
