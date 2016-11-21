#ifndef THREAD_END_H
#define THREAD_END_H
#include "Thread.h"
#include <map>
#include "common.h"
class Thread_End: public Thread{
public:
    Thread_End();//constructor
    virtual ~Thread_End();//destructor
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	//Thread_Ends for x seconds
private:
	Instructions * clone(std::vector<std::string> lines);// not implemented
};

#endif