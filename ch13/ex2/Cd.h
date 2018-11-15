#ifndef CD_H
#define CD_H value

/*! \class Cd
 *  \brief Brief class description
 *
 *  Detailed description
 */
class Cd
{
private:
    char * performers;
    char * lable;
    int selections;
    double playtime;
public:
    Cd(const char * s1, const char * s2, const int n, const double x);
    Cd(const Cd & d);
    Cd();
    ~Cd();
    virtual void Report() const;
    virtual Cd & operator=(const Cd & d);
};

#endif /* ifndef CD_H */
