#ifndef STACK_H
#define STACK_H 
#include <string>

struct customer
{
    std::string fullname;    
    double payment;
};

typedef customer Item;

class Stack
{
public:
    Stack();
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Item& items);
    bool pop(Item& items);
    void showTotal();
    enum {Max = 10};
private:
    Item items[Max];
    int top;
    double runningTotal;
};

#endif
