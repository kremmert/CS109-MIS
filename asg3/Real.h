#ifndef REAL_H
#define REAL_H
#include "Var.h"
#include "common.h"
#include <string.h>
class Real: public Var {
public:
    Real();
    Real(std::string n, std::string t, int v);
    virtual ~Real();
    std::string getName();
	int * getVal();
	Instructions * clone(std::vector<std::string>);
private:
    std::string name;
    std::string type;
    int val;


};
#endif