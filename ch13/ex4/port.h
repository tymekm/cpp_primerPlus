#ifndef PORT_H
#define PORT_H value
#include <iostream>
using std::ostream;

//-------------------------------------------------------------
// Port
//-------------------------------------------------------------

class Port
{
private:
    char * brand;
    char style[20];
    int bottles;
public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p);
    virtual ~Port(){delete [] brand;}
    Port & operator=(const Port & p);
    Port & operator+=(int b);
    Port & operator-=(int b);
    int bottleCount() const { return bottles;}
    virtual void show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};

//-------------------------------------------------------------
// VintagePort
//-------------------------------------------------------------

class VintagePort : public Port
{
private:
    char * nickname;
    int year;
public:
    VintagePort();
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    virtual ~VintagePort() { delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & p);
};

#endif /* ifndef PORT_H */
