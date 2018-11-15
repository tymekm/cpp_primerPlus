#include "cow.h"
#include <iostream>

int main()
{
    Cow milky("milky", "mooing", 200);
    milky.showCow();
    Cow temp;
    temp = milky;
    temp.showCow();
    Cow yetanothermilky(milky);
    yetanothermilky.showCow();
    return 0;
}
