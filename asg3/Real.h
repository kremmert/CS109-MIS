#ifndef REAL_H
#define REAL_H
#include "Var.h"
#include "common.h"
#include <string.h>
class Real: public Var {
public:
    Real();
    Real(std::string n, std::string t, double v);
    virtual ~Real();
    std::string getName();
	double * getVal();
    void setVal(double a);
	Instructions * clone(std::vector<std::string>);
private:
    std::string name;
    std::string type;
    double val;


};
#endif