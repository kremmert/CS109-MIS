#ifndef REAL_H
#define REAL_H
#include "Var.h"
#include "common.h"
#include <string.h>
class Real: public Var {
public:
	//blank constructor, data member populated later from clone function
    Real();
	//virtual destructor can delete from pointer to base class
    virtual ~Real();
private:
	//register/container name
	std::string name;
	//tells what data type this is; for multiple types of Var in one container
    std::string type;
	//Holds value, Reals are Decimal numeric values
    double val;
	
	void setVal(std::string a);
	//getter for type name in string
	std::string getName();
	//returns pointer to value
	double * getVal();
	//returns Real value as a string
	std::string getV();
	
	//allows construction of Real object to be done as a function call
	//done to allow the making of vars to be in a map of functions
	//takes parameters and converts from string when needed
	Real(std::string n, std::string t, double v);
	
	//takes parameters and converts from string when needed
	Instructions * clone(std::vector<std::string>);
};
#endif