#ifndef LOCK_H
#define LOCK_H
#include "Function.h"
#include <map>
#include "common.h"
class Lock: public Function{
public:
    Lock();//constructor
    virtual ~Lock();//destructor
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	//Locks for x seconds
private:
	Instructions * clone(std::vector<std::string> lines);// not implkemented
};

#endif