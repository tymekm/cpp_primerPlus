#include "Cd.h"

#ifndef CLASSIC_H
#define CLASSIC_H value

/*! \class Classic
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Classic : public Cd
{
private:
    char * primary;
public:
    Classic(const char * s1, const char * s2, const char * s3, int n, double x);
    Classic(const Classic & d);
    Classic();
    virtual ~Classic();
    virtual void Report() const;
    virtual Classic & operator=(const Classic & d);
};

#endif /* ifndef CLASSIC_H */
