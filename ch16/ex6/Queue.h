#ifndef QUEUE_H
#define QUEUE_H
#include <queue>
#include <cstdlib>

class Customer 
{
private:
    long arrive;
    int processTime;
public:
    Customer() : arrive(0), processTime(0) {}
    void set(long when);
    long when() const { return arrive; }
    int ptime() const { return processTime; }
};

class Queue 
{
private:
    const int MAX;
    std::queue<Customer> myQueue;
protected:
public:
    Queue(int qs) : MAX(qs) {}
    ~Queue() {}
    bool isEmpty() const { return myQueue.empty(); }
    bool isFull() const { return myQueue.size() == MAX; }
    int queueCount() const { return myQueue.size(); };
    bool endQueue(const Customer & c); 
    bool deQueue();
};

bool Queue::endQueue(const Customer & c) 
{
    if (isFull())
	return false;
    else
    {
	myQueue.push(c); 
	return true;
    }
}

bool Queue::deQueue()
{
    if(isEmpty())
	return false;
    else
    {
	myQueue.pop();
	return true;
    }
}

void Customer::set(long when)
{
    processTime = std::rand() % 3 + 1;
    arrive = when;
}

#endif
