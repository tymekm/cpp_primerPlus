#ifndef WORKER_H
#define WORKER_H
#include <string>

class Worker
{
private:
    std::string fullName;
    long id;
protected:
    void data() const;
    void get();
public:
    Worker()
	:fullName("no one"), id(0L){};
    Worker(const std::string & s, long n)
	:fullName(s), id(n){}
    virtual ~Worker() = 0;
    virtual void set() = 0;
    virtual void show() const = 0;
};

class Waiter : virtual public Worker
{
private:
    int panache;
protected:
    void data() const;
    void get();
public:
    Waiter()
	:Worker(), panache(0){}
    Waiter(const std::string & s, long n, int p = 0)
	:Worker(s,n), panache(p){}
    Waiter(const Worker & wk, int p = 0)
	:Worker(wk), panache(p){}
    void set();
    void show() const;
};

class Singer : virtual public Worker
{
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum {Vtypes = 7};
    void data() const;
    void get();
private:
    static const char *pv[Vtypes];
    int voice;
public:
    Singer()
	:Worker(), voice(other){}
    Singer(const std::string & s, long n, int v = other)
	:Worker(s, n), voice(v){}
    Singer(const Worker & wk, int v = other)
	:Worker(wk), voice(v){}
    void set();
    void show() const;
};

class SingerWaiter : public Singer, public Waiter
{
protected:
    void data() const;
    void get();
public:
    SingerWaiter(){};
    SingerWaiter(const std::string & s, long n, int p = 0, int v = other)
	:Worker(s,n), Waiter(s,n,p), Singer(s,n,v){}
    SingerWaiter(const Worker & wk, int p = 0, int v = other)
	:Worker(wk), Waiter(wk,p), Singer(wk,v){}
    SingerWaiter(const Worker & wk, const Waiter & wt, int v = other)
	:Worker(wk), Waiter(wt), Singer(wk,v){}
    SingerWaiter(const Singer & wt, int p = 0)
	:Worker(wt), Waiter(wt, p), Singer(wt){}
    void show() const;
    void set();
};

#endif
