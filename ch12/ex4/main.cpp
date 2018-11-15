#include "Stack.h"
#include <iostream>
#include <cctype>
#include <ctime>
#include <cstdlib>

using std::srand;
using std::rand;
using std::time;
using std::cout;
using std::cin;

int main()
{
    //srand(time(0));
    Stack st1(5);

    for (int i = 0; i < 4; i++) 
    {
        st1.push(rand());
    }
    cout << "St1: \n";
    cout << st1 << '\n';
    Stack st2(5);
    cout << "St2: \n";
    cout << st2 << '\n';
    st2 = st1;
    cout << st2 << '\n';
    Stack st3(st2);
    cout << "St3: \n";
    cout << st3 << '\n';
}
