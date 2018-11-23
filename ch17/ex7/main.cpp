#include "Store.h"

int main(int argc, const char *argv[])
{
    vector<string> vostr; 
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while (getline(cin, temp) && temp[0] != '\0')
	vostr.push_back(temp);
    cout << "Here is your input.\n";
    std::for_each(vostr.begin(), vostr.end(), ShowStr);

    std::ofstream fout("strings.dat", ios_base::out | ios_base::binary);
    std::for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    vector<string> vistr;
    std::ifstream fin("strings.dat", ios_base::in | ios_base::binary);
    if (!fin.is_open())
    {	
	std::cerr << "Could not open file for input." << std::endl;
	exit(EXIT_FAILURE);
    }
    GetStrs(fin, vistr);
    cout << "\nHere are the strings read from the file\n";
    std::for_each(vistr.begin(), vistr.end(), ShowStr);
    return 0;
}

void ShowStr(const string & str)
{
    cout << str << '\n';
}

void GetStrs(std::ifstream & is, std::vector<string> & v)
{
    string temps;
    int len;
    while (!is.eof())
    {	
	is.read((char *)&len, sizeof(std::size_t));
	char * tempc = new char[len+1];
	is.read(tempc, len);
	tempc[len] = '\0';
	temps = tempc;
	v.push_back(temps);
	delete [] tempc;
    }
}
