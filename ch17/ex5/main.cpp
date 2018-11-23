#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <set>

int main()
{
    using std::cout;
    using std::cerr;
    using std::string;
    using std::set;

    const string mat = "mat.dat";
    const string pat = "pat.dat";
    const string matnpat = "matnpat.dat";

    std::ifstream fin1(mat);
    std::ifstream fin2(pat);
    std::ofstream fout(matnpat);

    if (!fin1.is_open())
    {
	cerr << "Could  not open " << mat << "\n";
	exit(EXIT_FAILURE);
    }
    if (!fin2.is_open())
    {
	cerr << "Could  not open " << pat << "\n";
	exit(EXIT_FAILURE);
    }
    if (!fout.is_open())
    {
	cerr << "Could not open " << matnpat << "\n";
	exit(EXIT_FAILURE);
    }

    set<string> matSet;
    string temp;
    while (!fin1.eof())
    {
	getline(fin1, temp);	
	matSet.insert(temp);
    }
    set<string> patSet;
    while (!fin2.eof())
    {
	getline(fin2, temp);	
	patSet.insert(temp);
    }

    cout << "\nMat's friend list: \n";
    for (auto it : matSet)
	std::cout << it << '\n';
    cout << "\nPat's friend list: \n";
    for (auto it : patSet)
	std::cout << it << '\n';

    set<string> matnpatSet;
    matSet.insert(patSet.begin(), patSet.end());

    cout << "\nCombined friend list: \n";
    for (auto it : matSet)
    {
	std::cout << it << '\n';
	fout << it << '\n';
    }

    fin1.close();
    fin2.close();
    fout.close();
    return 0;
}
