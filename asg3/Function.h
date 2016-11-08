#ifndef FUNCTION_H
#define FUNCTION_H
#include "Instructions.h"
class Function: public Instructions{
public:
    Function();
    Function(const Function& orig);
    virtual ~Function();

	virtual Instructions * clone(std::vector<std::string>) = 0;
	virtual void functor(std::vector<std::string>) = 0;
private:

};

#endif