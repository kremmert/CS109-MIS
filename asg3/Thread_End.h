#ifndef THREAD_END_H
#define THREAD_END_H
#include "Function.h"
#include <map>
#include "common.h"
class Thread_End: public Function{
public:
    Thread_End();//constructor
    virtual ~Thread_End();//destructor
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	//Thread_Ends for x seconds
private:
	Instructions * clone(std::vector<std::string> lines);// not implkemented
};

#endif