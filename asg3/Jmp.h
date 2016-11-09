#ifndef JMP_H
#define JMP_H
#include "Function.h"
#include <map>
#include "common.h"
class Jmp: public Function{
public:
    Jmp();
    Jmp(const Jmp& orig);
    virtual ~Jmp();
	virtual void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	Instructions * clone(std::vector<std::string> lines);
};

#endif