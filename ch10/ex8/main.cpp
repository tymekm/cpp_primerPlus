#include "list.h"

int main()
{
	List list1;
	cout << list1.isEmpty() << '\n';
	list1.add(50);

	list1.showList();

	while (list1.isFull() == false)
		list1.add(9);

	list1.showList();
}
