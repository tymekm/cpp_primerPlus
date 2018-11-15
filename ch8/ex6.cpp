// ex6.cpp
#include <iostream>
#include <array>
#include <algorithm>
#include <string>

template<class T>
T maxn(T arr[], const int SIZE);
std::string maxn(std::array<std::string, 4> sarr);

int main()
{
    const int intSIZE = 6;
    int iarr[intSIZE] = {5,3,7,8,4, 2};
    std::cout << maxn(iarr, intSIZE) << '\n';

    const int doubleSIZE = 4;
    double darr[doubleSIZE] = {5.76,9.92,7.12,8.73};
    std::cout << maxn(darr, doubleSIZE) << '\n';

    const int stringSize = 4;
    std::array<std::string, stringSize> sarray = {"hello", "ok", "i", "banana"};
    std::cout << maxn(sarray);
}

template<class T>
T maxn(T arr[], const int SIZE)
{
    using namespace std;
    sort(arr, arr + SIZE);
    return arr[SIZE - 1];
}

std::string maxn(std::array<std::string, 4> sarr)
{
    using namespace std;
    sort(begin(sarr), end(sarr), [](const std::string &s1, const std::string &s2) {return s1.size() > s2.size(); });
    return sarr[0];
}
