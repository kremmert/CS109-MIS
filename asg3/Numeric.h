#ifndef NUMERIC_H
#define NUMERIC_H
#include "var.h"
#include "common.h"
#include <string.h>
class Numeric: public Var {
public:
    Numeric();
    Numeric(std::string n, std::string t, int v);
    virtual ~Numeric();
    std::string getName();
	int * getVal();
	Var * clone(std::vector<std::string>);
private:
    std::string name;
    std::string type;

    int val;

};
#endif