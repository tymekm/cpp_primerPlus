#include <iostream>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::string;

int main()
{
    cout << "Enter a word to check (quit to exit): ";
    string strOrig;
    while (getline(cin, strOrig) && strOrig != "quit")
    {
	string str = strOrig;
	std::transform(str.begin(), str.end(), str.begin(),::tolower);
	str.erase(remove_if(str.begin(), str.end(), [](char c) { return !isalpha(c); } ), str.end());
	string strRev = str;
	std::reverse(strRev.begin(), strRev.end());

	if (str == strRev)
	    cout << strOrig << " is a palindrome!\n";
	else
	    cout << strOrig << " is not a palindrome!\n";
	cout << "Enter another word: ";
    }

    cout << "Bye!\n";

    return 0;
}
