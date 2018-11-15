#include "Stack.h"
#include <iostream>

Stack::Stack(int n)
{
    if (n > MAX)
    {
	std::cout << "Maximum stack size allowed is " 
	    << MAX << "\nAborting...\n";
    }
    else
    {
	pitem = new Item[n];
	size = n;
    }
    
}

Stack::Stack(const Stack & st)
{
    pitem = new Item[st.size];
    size = st.size;
    top = st.top;

    for (int i = 0; i < size; i++) {
	pitem[i] = st.pitem[i];    
    }
}

Stack::~Stack()
{
    delete [] pitem;
}

bool Stack::isempty() const
{
    return top == 0;;
}

bool Stack::isfull() const
{
    return top == MAX;;
}

bool Stack::push(const Item & item)
{
    if (!isfull())
    {
	pitem[top++] = item;	
	return true;
    }
    else
	return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {

	item = pitem[--top];
	pitem[top] = 0;
	return true;
    }
    else
	return false;
}

Stack & Stack::operator=(const Stack & st)
{
    pitem = new Item[st.size];
    size = st.size;
    top = st.top;
    for (int i = 0; i < size; i++) {
       pitem[i] = st.pitem[i]; 
    }
    return *this;;
}

ostream & operator<<(ostream & os, const Stack & st)
{
    using std::cout;
    cout << '[';
    for (int i = 0; i < st.size; i++) {
	cout << st.pitem[i] << ", ";    
    }
    cout << "\b\b]";
    return os;
}
