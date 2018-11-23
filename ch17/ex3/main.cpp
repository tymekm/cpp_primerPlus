#include <iostream>
#include <fstream>
#include <cstdlib>

using std::string;

int main(int argc, const char *argv[])
{
    std::ifstream fin(argv[1]);
    std::ofstream fout(argv[2]);

    if (argc < 3)
    {
	std::cerr << "Usage: " << argv[0] << " \"infile\" \"outfile\"\n";
	exit(EXIT_FAILURE);
    }

    if (!fin.is_open())
    {
	std::cerr << "Error: could not open input file.\n";
    }

    char ch;

    while (fin.get(ch))
	fout << ch;
    fout << std::flush;

    fin.close();
    fout.close();
    return 0;
}
