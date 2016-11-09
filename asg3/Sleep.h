#ifndef SLEEP_H
#define SLEEP_H
#include "Function.h"
#include <map>
#include "common.h"
class Sleep: public Function{
public:
    Sleep();//constructor
    Sleep(const Sleep& orig);
    virtual ~Sleep();//destructor
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	//sleeps for x seconds
private:
	Instructions * clone(std::vector<std::string> lines);// not implkemented
};

#endif