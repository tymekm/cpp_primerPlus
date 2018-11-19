#include <iostream>
#include <set>
#include <algorithm>
#include <string>

int main()
{
    using std::cout;
    using std::cin;
    using std::set;
    using std::string;

    cout << "Enter Mat's friend list (enter after each name, quit when done)\n";
    string temp;
    set<string> mat;
    while (getline(cin, temp) && temp != "quit")
	mat.insert(temp);

    set<string> pat;
    cout << "Enter Pat's friend list (enter after each name, quit when done)\n";
    while (getline(cin, temp) && temp != "quit")
	pat.insert(temp);

    mat.insert(pat.begin(), pat.end());

    cout << "Here's your combined list of invites: \n";
    for (auto it : mat)
	cout << '\"' << it << "\", ";
    cout << "\b\b\b\b\n";
}
