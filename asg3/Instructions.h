#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <map>
#include "common.h"

class Instructions {
public:
    Instructions();
    Instructions(const Instructions& orig);
    virtual ~Instructions();
	virtual Instructions * clone(std::vector<std::string>) = 0;
    virtual std::string getV() =0;
    virtual void setVal(std::string a)=0;
	virtual void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy) = 0;
private:
    



};
#endif