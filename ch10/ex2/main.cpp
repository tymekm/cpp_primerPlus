#include <iostream>
#include <string>
#include "person.h"

int main()
{
    Person one;
    Person two {"Smythercraft"};
    Person three {"Dimwiddy", "Sam"};

    one.show();
    one.formalShow();
    two.show();
    two.formalShow();
    three.show();
    three.formalShow();
}
