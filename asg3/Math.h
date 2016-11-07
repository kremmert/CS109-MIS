#ifndef MATH_H
#define MATH_H
#include "Instructions.h"
class Math: public Instructions{
public:
    Math();
    Math(const Math& orig);
    virtual ~Math();
private:
	Instructions * clone(std::vector<std::string>);
    


};
#endif