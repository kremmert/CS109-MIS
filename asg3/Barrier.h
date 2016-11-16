#ifndef BARRIER_H
#define BARRIER_H
#include "Function.h"
#include <map>
#include "common.h"
class Barrier: public Function{
public:
    Barrier();//constructor
    virtual ~Barrier();//destructor
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	//Barriers for x seconds
private:
	Instructions * clone(std::vector<std::string> lines);// not implkemented
};

#endif