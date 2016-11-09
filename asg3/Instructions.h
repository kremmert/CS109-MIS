#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <map>
#include "common.h"

class Instructions {
public:
    Instructions();//constructor
    Instructions(const Instructions& orig);
    virtual ~Instructions();
	virtual Instructions * clone(std::vector<std::string>) = 0;//used by variable classes
    virtual std::string getV() =0;//virtual, will be inherited by everything. used for numbers and strings
    virtual void setVal(std::string a)=0;//change the value
	virtual void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy) = 0;
	//functor is used by function objects. each one is unique to their function class (add is unique to sub) etc
private:
    



};
#endif