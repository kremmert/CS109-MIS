#ifndef SLEEP_H
#define SLEEP_H
#include "Function.h"
#include <map>
#include "common.h"
class Sleep: public Function{
public:
    Sleep();
    Sleep(const Sleep& orig);
    virtual ~Sleep();
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	Instructions * clone(std::vector<std::string> lines);
};

#endif