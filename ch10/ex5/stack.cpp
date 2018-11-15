#include "stack.h"
#include <iostream>
#include <string>

Stack::Stack()
{
    top = 0;
}

bool Stack::isEmpty() const
{
    return top == 0;
}

bool Stack::isFull() const
{
    return top == Max;
}

bool Stack::push(const Item& item)
{
    if (top < Max)
    {
	items[top++] = item;
	return true;
    }
    return false;
}

bool Stack::pop(Item& item)
{
    if (top > 0)
    {
	runningTotal += items[top - 1].payment;
	showTotal();
	item = items[--top];
	return true;
    }
    return false;
}

void Stack::showTotal()
{
    std::cout << "Current runnign total = $" << runningTotal << '\n';
}
