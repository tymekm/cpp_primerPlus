#ifndef STACK_H
#define STACK_H
#include <iostream>
typedef unsigned long Item;
using std::ostream;

class Stack
{
private:
    enum {MAX = 10};
    Item * pitem;
    int size = 0;
    int top = 0;
public:
    Stack (int n = MAX);
    Stack(const Stack & st);
    ~Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item & item);
    bool pop(Item & item);
    Stack & operator=(const Stack & st);
    friend ostream & operator<<(ostream & os, const Stack & st);
};

#endif
