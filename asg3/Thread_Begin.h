#ifndef THREAD_BEGIN_H
#define THREAD_BEGIN_H
#include "Function.h"
#include <map>
#include "common.h"
class Thread_Begin: public Function{
public:
    Thread_Begin();//constructor
    virtual ~Thread_Begin();//destructor
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	//Thread_Begins for x seconds
private:
	Instructions * clone(std::vector<std::string> lines);// not implkemented
};

#endif