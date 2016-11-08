#ifndef MATH_H
#define MATH_H
#include "Function.h"
#include <map>
class Math: public Function{
public:
    Math();
    Math(const Math& orig);
    virtual ~Math();
	virtual void functor(std::vector<std::string>,std::map <std::string,Instructions *> & mapy) = 0;
private:
	Instructions * clone(std::vector<std::string> lines);
    


};
#endif