#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class abstr_emp 
{
protected:
    typedef std::string string;
    virtual void Data() const = 0;
    virtual void Get() = 0;
private:
    string fname;
    string lname;
    string job;
public:
    abstr_emp()
	:fname("none"), lname("none"), job("none") {}
    abstr_emp(const string & fn, const string ln, const string & j)
	:fname(fn), lname(ln), job(j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
    virtual ~abstr_emp() = 0;
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
};

class Employee : public abstr_emp
{
protected:
    virtual void Data() const {};
    virtual void Get() {};
public:
    Employee()
	:abstr_emp() {}
    Employee(const string & fn, const string ln, const string & j)
	:abstr_emp(fn, ln, j) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

class Manager : virtual public abstr_emp
{
private:
    int inchargeof;    
protected:
    int inChargeOf() const { return inchargeof; }
    int & inChargeOf() { return inchargeof; }
    void Data() const;
    void Get();
public:
    Manager()
	:abstr_emp(), inchargeof(0) {}
    Manager(const string & fn, const string ln, const string & j, const int ico = 0)
	:abstr_emp(fn, ln, j), inchargeof(ico) {}
    Manager(const abstr_emp & e, int ico)
	:abstr_emp(e), inchargeof(ico) {}
    Manager(const Manager & m)
	:abstr_emp(m) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

class Fink : virtual public abstr_emp
{
private:
    string reportsto;
protected:
    const string ReportsTo() const { return reportsto; }
    string & ReportsTo() { return reportsto; }
    void Data() const;
    void Get();
public:
    Fink()
	:abstr_emp(), reportsto("") {}
    Fink(const string & fn, const string ln, const string & j,
	    const string & rpo)
	:abstr_emp(fn, ln, j), reportsto(rpo) {}
    Fink(const abstr_emp & e, const string & rpo)
	:abstr_emp(e), reportsto(rpo) {}
    Fink(const Fink & f);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class HighFink : public Manager, public Fink
{
protected:
    void Data() const {};
    void Get() {};
public:
    HighFink()
	:abstr_emp(), Manager(), Fink() {}
    HighFink(const string & fn, const string ln, const string & j,
	    const int ico, const string & rpo)
	:abstr_emp(fn, ln, j), Manager(fn, ln, j, ico), Fink(fn, ln, j, rpo) {}
    HighFink(const abstr_emp & e, const int ico, const string & rpo)
	:abstr_emp(e), Manager(e, ico), Fink(e, rpo) {}
    HighFink(const Fink & f, int ico)
	:abstr_emp(f), Manager(f, ico), Fink(f) {}
    HighFink(const Manager & m, const string & rpo)
	:abstr_emp(m), Manager(m), Fink(m, rpo) {}
    HighFink(const HighFink & h)
	:abstr_emp(h), Manager(h), Fink(h) {}
    virtual void ShowAll() const;
    virtual void SetAll();
};

#endif
