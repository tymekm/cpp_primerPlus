#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <valarray>
const int NUM = 3;

using std::cout;

template <typename T>
int reduce(T arr[], int n);

int main()
{
    std::string stringArr[NUM] {"one", "one", "two"};
    int result = reduce(stringArr, NUM);
    std::cout << result;
    std::cout << '\n';

    long longArr[NUM] {5,7,5};
    result = reduce(longArr, NUM);
    std::cout << result;
    std::cout << '\n';
    return 0;
}

template <typename T>
int reduce(T arr[], int n)
{
    std::vector<T> vec(arr, arr+n);
    std::sort(vec.begin(), vec.end());
    vec.erase( std::unique( vec.begin(), vec.end() ), vec.end() );
    return vec.size();
}
