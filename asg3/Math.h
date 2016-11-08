#ifndef MATH_H
#define MATH_H
#include "Function.h"
class Math: public Function{
public:
    Math();
    Math(const Math& orig);
    virtual ~Math();
	virtual void functor(std::vector<std::string>) = 0;
private:
	Instructions * clone(std::vector<std::string> lines);
    


};
#endif