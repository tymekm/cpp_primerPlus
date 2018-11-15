#include "Dma.h"
#include <cstring>

using std::strlen;
using std::strcpy;
using std::ostream;
using std::cout;

//-------------------------------------------------------------
// BaseDma
//-------------------------------------------------------------

BaseDma::BaseDma(const char * l, const int r)
{
    label = new char[strlen(l) + 1];
    strcpy(label, l);
    rating = r;
}

BaseDma * BaseDma::clone() const
{
    return new BaseDma(*this);
}

BaseDma::~BaseDma()
{
    delete [] label;
}

BaseDma & BaseDma::operator=(const BaseDma & rd)
{
    label = new char[strlen(rd.label) + 1];
    strcpy(label, rd.label);
    rating = rd.rating;
    return *this;
}

void BaseDma::show() const
{
    std::cout << "Label: " << label << ", rating: " << rating << '\n';
}

//-------------------------------------------------------------
// LacksDma
//-------------------------------------------------------------

LacksDma::LacksDma(const char * c)
{
    strcpy(color, c);
}

LacksDma * LacksDma::clone() const
{
    return new LacksDma(*this);
}

LacksDma & LacksDma::operator=(const LacksDma & rd)
{
    strcpy(color, rd.color);
    return *this;
}

void LacksDma::show() const
{
    std::cout << "Label: " << color;
}

//-------------------------------------------------------------
// HasDma
//-------------------------------------------------------------

HasDma::HasDma(const char * s)
{
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

HasDma * HasDma::clone() const
{
    return new HasDma(*this);
}

HasDma::~HasDma()
{
    delete [] style;
}

HasDma & HasDma::operator=(const HasDma & rd)
{
    style = new char[strlen(rd.style) + 1];
    strcpy(style, rd.style);
    return *this;
}

void HasDma::show() const
{
    cout << "Style: " << style << '\n';
}
