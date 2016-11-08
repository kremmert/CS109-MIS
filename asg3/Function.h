#ifndef FUNCTION_H
#define FUNCTION_H
#include "Instructions.h"
#include <map>
class Function: public Instructions{
public:
    Function();
    Function(const Function& orig);
    virtual ~Function();
    std::string getV(){return "a";}
    void setVal(std::string a) {}
	virtual Instructions * clone(std::vector<std::string>) = 0;
	virtual void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy) = 0;
private:

};

#endif