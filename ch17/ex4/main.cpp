#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main()
{
    using std::cerr;
    using std::string;

    std::ifstream fin1("infile1");
    std::ifstream fin2("infile2");
    std::ofstream fout("outfile");

    if (!fin1.is_open())
	cerr << "Could  not open infile1\n";
    if (!fin2.is_open())
	cerr << "Could  not open infile2\n";
    if (!fout.is_open())
	cerr << "Could not open outfile\n";

    string temp;
    while (!fin1.eof() || !fin2.eof())
    {
	getline(fin1, temp);
	fout << temp;
	getline(fin2, temp);
	fout << temp;
	fout << '\n';
    }

    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}
