#ifndef MEAN_H
#define MEAN_H
#include <stdexcept>

class bad_hmean : public std::logic_error
{
public:
    explicit bad_hmean(const std::string & s =  "Bad arguments to hmean")
	:logic_error(s) {}
};

class bad_gmean : public std::logic_error
{
public:
    explicit bad_gmean(const std::string & s =  "Bad arguments to gmean")
	:logic_error(s) {}
};

#endif
