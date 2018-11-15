#include "move.h"
#include <iostream>

int main()
{
    Move someMove {2, 4};

    someMove.showMove();

    someMove.reset(50,100);
    someMove.showMove();

    Move someMove2 {100, 500};

    someMove.add(someMove2).showMove();

}
