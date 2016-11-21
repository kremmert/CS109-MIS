#ifndef THREAD_BEGIN_H
#define THREAD_BEGIN_H
#include "Thread.h"
#include <map>
#include "common.h"
class Thread_Begin: public Thread{
public:
    Thread_Begin();//constructor
    virtual ~Thread_Begin();//destructor
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	//Thread_Begins for x seconds
private:
	Instructions * clone(std::vector<std::string> lines);// not implemented
};

#endif