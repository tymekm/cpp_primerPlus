#include "port.h"

int main()
{
    using std::cout;
    const int MAX = 5;

    Port * collection[MAX];
    collection[0] = new Port("brand", "cheapwine", 2018);
    cout << *collection[0];

    return 0;
}
