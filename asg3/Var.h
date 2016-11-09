#ifndef VAR_H
#define VAR_H
#include "common.h"
#include <stdlib.h>
#include "Instructions.h"
#include <map>
class Var: public Instructions{
//inherit instructions to have a unified call for all instructions
public:
	//constructor
    Var();
	//virtual destructor can delete from pointer to base class
    virtual ~Var();
	
    virtual std::string getV() =0;
	//setVal used in other instructions to give access to private class variables
    virtual void setVal(std::string a)=0;
	
	//ensure function needs to implement a clone function
	//clone used to change parameters given as a string into other data types when needed
	//i.e. converting number literals from string to integer
	virtual Instructions * clone(std::vector<std::string>) = 0;
private:
	//is not used for Var descendants
	//made private so it will no longer be virtual or inherited
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){};
	//copy constructor discontinued for descendants(UNUSED)
    Var(const Var& orig);
};

#endif
