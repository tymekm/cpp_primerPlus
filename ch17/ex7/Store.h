#ifndef STORE_H
#define STORE_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ios_base;

void ShowStr(const string & str);
void GetStrs(std::ifstream & is, std::vector<string> & v);

class Store 
{
private:
    std::ofstream & fout;
public:
    Store(std::ofstream & os)
	:fout(os) {}
    void operator()(const string & str);
};

void Store::operator()(const string & str)
{
    //This would have been so much easier...
    //fout << str << '\n';
    int len = str.size(); 
    fout.write((char *)&len, sizeof(std::size_t));
    fout.write(str.data(), len);
}

#endif
