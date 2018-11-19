#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;

int main()
{
    cout << "Enter a word to check (quit to exit): ";
    string str;
    while (cin >> str && str != "quit")
    {
	std::transform(str.begin(), str.end(), str.begin(),::tolower);
	string strRev = str;
	std::reverse(strRev.begin(), strRev.end());

	if (str == strRev)
	    cout << str << " is a palindrome!\n";
	else
	    cout << str << " is not a palindrome!\n";
	cout << "Enter another word: ";
    }

    cout << "Bye!\n";

    return 0;
}
