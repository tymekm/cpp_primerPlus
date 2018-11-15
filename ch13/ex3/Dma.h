
#ifndef DMA_H
#define DMA_H value
#include <iostream>

/*! \class DmaABC
 *  \brief Brief class description
 *
 *  Detailed description
 */
class DmaABC
{
private:
public:
    DmaABC(){};
    virtual ~DmaABC(){};
    virtual DmaABC* clone() const = 0;
    virtual void show() const = 0;
};

class BaseDma : public DmaABC
{
private:
    char * label;
    int rating;
public:
    BaseDma(const char * l, const int r);
    ~BaseDma();
    BaseDma* clone() const;
    BaseDma & operator=(const BaseDma & rd);
    void show() const;
};

class LacksDma : public DmaABC
{
private:
    enum { COL_LEN = 40};
    char color[COL_LEN];
public:
    LacksDma(const char * c = "Blank");
    ~LacksDma(){};
    LacksDma* clone() const;
    LacksDma & operator=(const LacksDma & rd);
    void show() const;
};

class HasDma : public DmaABC
{
private:
    char * style;
public:
    HasDma(const char * s = "none");
    ~HasDma();
    HasDma* clone() const;
    HasDma & operator=(const HasDma & rd);
    void show() const;
};

#endif /* ifndef DMA_H */
