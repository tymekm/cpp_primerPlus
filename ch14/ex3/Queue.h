#ifndef QUEUE_H
#define QUEUE_H
#include "Worker.h"

template <typename T>
class Queue
{
private:
    struct Node
    {
	T item;
	struct Node * next;
    };
    const int Q_SIZE;
    Node * front;
    Node * rear;
    int items;
    Queue(const Queue & q)
	: Q_SIZE(0){};
    Queue & operator=(const Queue & q) { return * this; }
public:
    Queue(const int qs = 10)
	:front(nullptr), rear(nullptr), items(0), Q_SIZE(qs) {}
    ~Queue();
    bool isEmpty() const { return items == 0; }
    bool isFull() const { return items == Q_SIZE; }
    int queueCount() const { return items; }
    bool endQueue(const T item);
    bool deQueue(T item);
    T operator[](const int iEnd) ;
};

template<typename T>
Queue<T>::~Queue()
{
    Node * temp;
    while (!isEmpty())
    {
	temp = front;
	front = front->next;
	delete temp;
    }
}

template<typename T>
bool Queue<T>::endQueue(const T item)
{
    if (isFull())
	return false;
    Node * add = new Node;
    add->item = item;
    add->next = nullptr;
    items++;
    if (front == nullptr)
	front = add;
    else
	rear->next = add;
    rear = add;
    return true;
}

template<typename T>
bool Queue<T>::deQueue(T item)
{
    if (front == nullptr)
	return false;
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
	rear = nullptr;
    return true;
}

template<typename T>
T Queue<T>::operator[](const int iEnd)
{
    Node * current = front;
    int i;
    for (i = 0; i < iEnd; i++) 
        current = current->next; 
    return current->item;
}

#endif
