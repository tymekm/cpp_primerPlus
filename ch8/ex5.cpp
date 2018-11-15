// ex5.cpp
#include <iostream>
#include <algorithm>
#include <array>

template<class T> T max5(std::array<T, 5> ar);

int main()
{
    std::array<double, 5> darray;
    darray = {9.5,2.5,3.5,4.5,5.5};
    std::array<int, 5> iarray;
    iarray = {1,2,3,4,5};

    std::cout << max5(darray) << '\n';
    std::cout << max5(iarray) << '\n';
}

template<class T>
T max5(std::array<T, 5> ar)
{
    using namespace std;
    std::sort(ar.begin(), ar.end());
    return ar[ar.size() - 1];    
}
