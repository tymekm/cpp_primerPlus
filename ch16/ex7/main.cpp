#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

typedef std::vector<int> intVec;

intVec Lotto(const int n, const int toSelect);

int main()
{
    std::srand(std::time(0));
    intVec winner;
    winner = Lotto(61, 6);
    for (auto it : winner)
	std::cout << it << ' ';
    std::cout << '\n';

    winner = Lotto(49, 3);
    for (auto it : winner)
	std::cout << it << ' ';
    std::cout << '\n';
}

intVec Lotto(const int n, const int toSelect)
{
    intVec possibleNums(n);
    for (int i = 0; i < n; i++) 
    {
	possibleNums[i] = i;    
    }
    std::random_shuffle(possibleNums.begin(), possibleNums.end());
    intVec winner(toSelect);
    auto rangeEnd = possibleNums.begin() + toSelect;
    std::copy(possibleNums.begin(), rangeEnd, winner.begin());
    return winner;
}
