#ifndef VAR_H
#define VAR_H
#include "common.h"
#include <stdlib.h>
#include "Instructions.h"
class Var: public Instructions{
public:
    Var();
    Var(const Var& orig);
    virtual ~Var();
    virtual std::string getName();
/*	virtual int * getVal();
    virtual double * getVal();
    virtual std::string getVal();
    virtual char getVal(); */
    Var * decode(std::vector<std::string> lines);
	virtual Instructions * clone(std::vector<std::string>) = 0;
private:
    std::string varType;
    std::string name;
    std::string type;
    std::string val;
};

#endif
