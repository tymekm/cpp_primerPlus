#include <iostream>
#include <vector>
#include <iterator>
#include <set>
#include <valarray>
const int NUM = 10;

int reduce(int arr[], int n);

int main()
{
    int numberArr[NUM] {1,4,4,5,9,3,2,2,7,7};
    int result = reduce(numberArr, NUM);
    std::cout << result;
    return 0;
}

int reduce(int arr[], int n)
{
    std::set<int> tempSet;
    tempSet.insert(arr, arr + n);
    return tempSet.size();
}
