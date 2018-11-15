#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person 
{
protected:
    typedef std::string string;
    virtual void Data() const;
    virtual void Get();
private:
    string firstName;
    string lastName;
public:
    Person()
	:firstName("unknown"), lastName("unknown") {}
    Person(const string & fn, const string & ln)
	:firstName(fn), lastName(ln) {}
    virtual ~Person() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Gunslinger : virtual public Person
{
private:
    double drawTime;
    int nothes;
protected:
    void Data() const;
    void Get();
public:
    Gunslinger()
	:Person(), drawTime((double)0), nothes(0) {}
    Gunslinger(const string & fn, const string & ln,
	    const double dt, const int n)
	:Person(fn, ln), drawTime(dt), nothes(n) {}
    Gunslinger(const Person & p, const double dt, const int n)
	:Person(p), drawTime(dt), nothes(n) {}
    double Draw() const { return drawTime; }
    void Set();
    void Show() const;
};

class PokerPlayer : virtual public Person
{
protected:
    void Data() const {};
    void Get() {};
public:
    PokerPlayer() 
	: Person() {}
    PokerPlayer(const string & fn, const string & ln)
	:Person(fn,ln) {}
    PokerPlayer(const Person & p)
	:Person(p) {}
    int Draw() const;
    void Set();
    void Show() const; 
};

class BadDude : public Gunslinger, public PokerPlayer
{
protected:
    void Data() const;
    void Get() {};
public:
    BadDude() {}
    BadDude(const string & fn, const string & ln,
	    const double dt, const int n)
	:Person(fn, ln), Gunslinger(fn,ln,dt,n), PokerPlayer(fn,ln) {}
    BadDude(const Person & p, const double dt, const int n)
	:Person(p), Gunslinger(p,dt,n), PokerPlayer(p) {}
    BadDude(const Gunslinger & gs)
	:Person(gs), Gunslinger(gs), PokerPlayer(gs) {}
    BadDude(const PokerPlayer & pp, const double dt, const int n)
	:Person(pp), Gunslinger(pp,dt,n), PokerPlayer(pp) {}
    void Set();
    void Show() const; 
    double gDraw() const;
    int cDraw() const;
};

#endif
