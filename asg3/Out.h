#ifndef OUT_H
#define OUT_H
#include "Function.h"
#include <map>
#include "common.h"
class Out: public Function{
public:
    Out();
    Out(const Out& orig);
    virtual ~Out();
    std::vector<std::string> outputV(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	Instructions * clone(std::vector<std::string> lines);
};

#endif