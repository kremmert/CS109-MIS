#ifndef ASSIGN_H
#define ASSIGN_H
#include "Function.h"
#include <map>
#include "common.h"
class Assign: public Function{
public:
    Assign();
    Assign(const Assign& orig);
    virtual ~Assign();
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	Instructions * clone(std::vector<std::string> lines);
};

#endif