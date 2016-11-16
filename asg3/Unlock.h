#ifndef UNLOCK_H
#define UNLOCK_H
#include "Function.h"
#include <map>
#include "common.h"
class Unlock: public Function{
public:
    Unlock();//constructor
    virtual ~Unlock();//destructor
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	//Unlocks for x seconds
private:
	Instructions * clone(std::vector<std::string> lines);// not implkemented
};

#endif