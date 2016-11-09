#ifndef NUMERIC_H
#define NUMERIC_H
#include "Var.h"
#include "common.h"
#include <string.h>
class Numeric: public Var {
public:
	//blank constructor, data member populated later from clone function
    Numeric();
	//virtual destructor can delete from pointer to base class
    virtual ~Numeric();       	
private:
	//register/container name
	std::string name;
	//tells what data type this is; for multiple types of Var in one container
    std::string type;
	//Holds value, Numerics are non-decimal numeric values
	int val;
	
	//setter for Numeric value
	void setVal(std::string a);
	//getter for type name in string
	std::string getName();
	//returns pointer to value
	int * getVal();
	//returns value as a string
	std::string getV();
	
	//allows construction of Numeric object to be done as a function call
	//done to allow the making of vars to be in a map of functions
	//takes parameters and converts from string when needed
	Numeric(std::string n, std::string t, int v);
	
	//takes parameters and converts from string when needed
    Instructions * clone(std::vector<std::string>);
};
#endif