#ifndef QUEUE_H
#define QUEUE_H 

class Customer
{
private:
    long arrive;
    int processtime;
public:
    Customer(){arrive = processtime = 0;}
    void set(long when);
    long when() const {return arrive;}
    long ptime() const {return processtime;}
};

class Queue
{
private:
    struct Node 
    {
	Customer item;
	struct Node * next; 
    };
    enum {Q_SIZE = 10};
    Node * front;
    Node * rear;
    int items;
    const int qsize;
    Queue(const Queue & q) : qsize(0) {}
    Queue & operator=(const Queue & q) {return *this;}
public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int queueCount() const;
    bool endQueue(const Customer & item);
    bool deQueue(Customer & item);
};

#endif
