#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::cout;
using std::cin;

class List
{
private:
	const static int LISTMAX = 10;
	//int intList[LISTMAX];
	vector<int> intList;
	int position = 0;

public:
	List();
	bool add(int toAdd);
	bool isFull() const;	
	bool isEmpty() const;	
	int& getItem(int index);
	void showList() const;
};

#endif
