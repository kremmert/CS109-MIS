#ifndef ASSIGN_H
#define ASSIGN_H
#include "Function.h"
#include <map>
#include "common.h"
class Assign: public Function{
public:
    Assign();//constructor
    Assign(const Assign& orig);//copy
    virtual ~Assign();//destructor
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	// vector of a line of instructions, map oy variables. assign a variable a value
private:
	Instructions * clone(std::vector<std::string> lines);//forced to implement not used
};

#endif