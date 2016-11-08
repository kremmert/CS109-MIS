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
    void setVal(std::string a);
    std::string getV();
	Instructions * clone(std::vector<std::string>);
private:
    std::string name;
    std::string type;

    int val;

};
#endif