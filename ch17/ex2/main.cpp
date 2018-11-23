#include <iostream>
#include <fstream>
#include <string>

int main()
{
    using std::string;
    using std::cin;
    using std::cout;
    using std::ios_base;

    cout << "Enter name of file: ";
    string fname;
    cin >> fname;

    std::ofstream fout(fname, ios_base::out | ios_base::app); 
    cout << "Enter data to be written to file: \n";
    char ch;
    while (fout.is_open())
    {
	cin.get(ch);
	fout << ch << std::flush;
    }
    cout << "Done\n";
    return 0;
}
