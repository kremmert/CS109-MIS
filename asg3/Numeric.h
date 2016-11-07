#ifndef NUMERIC_H
#define NUMERIC_H
#include "Var.h"
#include "common.h"
#include <string.h>
class Numeric: public Var {
public:
    Numeric();
    Numeric(std::string n, std::string t, int v);
    virtual ~Numeric();
    std::string getName();
	int * getVal();
    void setVal(int a);
	Instructions * clone(std::vector<std::string>);
private:
    std::string name;
    std::string type;

    int val;

};
#endif