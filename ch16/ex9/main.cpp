#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <algorithm>

typedef std::vector<int> intVec;
typedef std::list<int> intList;
using std::cout;
using std::rand;
const int SIZE = 10000000;

int main()
{
    std::srand(std::time(0));
    intVec vi0(SIZE);
    std::generate(vi0.begin(), vi0.end(), rand);

    intVec vi = vi0;
    intList li(SIZE);
    std::copy(vi0.begin(), vi0.end(), li.begin());

    clock_t start1 = clock();
    sort(vi.begin(), vi.end());
    clock_t end1 = clock();

    cout << "time elapsed using sort() algorithm on array: "
	<< (double) (end1 - start1)/CLOCKS_PER_SEC << '\n';

    clock_t start2 = clock();
    li.sort(); 
    clock_t end2 = clock();

    cout << "time elapsed using sort() on list: "
	<< (double) (end2 - start2)/CLOCKS_PER_SEC << '\n';
}
