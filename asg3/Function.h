#ifndef FUNCTION_H
#define FUNCTION_H
#include "Instructions.h"
#include <map>
class Function: public Instructions{
public:
    Function();//constructor
    Function(const Function& orig);
    virtual ~Function();//destructor
    std::string getV(){return "a";}//not used by function class. had to be implemented
    void setVal(std::string a) {}//not used by function obbjects. implemented because it was inherited
	virtual Instructions * clone(std::vector<std::string>) = 0;//not used by functions
	virtual void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy) = 0;
	//used by function children. unique to each class
private:

};

#endif