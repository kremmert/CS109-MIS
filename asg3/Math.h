#ifndef MATH_H
#define MATH_H
#include "Function.h"
class Math: public Function{
public:
    Math();
    Math(const Math& orig);
    virtual ~Math();
private:
	Instructions * clone(std::vector<std::string> lines);
    


};
#endif