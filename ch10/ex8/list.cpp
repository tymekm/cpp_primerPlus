#include "list.h"

List::List()
{
}

bool List::add(int toAdd)
{
	if (List::isFull())
		return false;
	else
	{
		intList.push_back(toAdd);
		position ++;
		return true;
	}
}

bool List::isFull() const
{
	if (intList.size() == LISTMAX)
		return true;
	else
		return false;
}

bool List::isEmpty() const
{
	return intList.empty();
}

int& List::getItem(int index)
{
	return intList.at(index);
}

void List::showList() const
{
	cout << '['; 	
	for (auto it = intList.begin(); it != intList.end(); ++it) {
		cout << *it << ", ";
	}
	cout << "\b\b]\n";
}
