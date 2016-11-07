#include "Real.h"
Real::Real(){}

Real::Real(std::string n, std::string t, int v):name(n), type(t), val(v) {}

Real::~Real() {}

std::string Real::getName()
{
    return this->name;
}

Var * Real::clone(std::vector<std::string> lines){
	Var * b = new Real(lines[1],lines[2],stoi(lines[3]));
	return b;
	
}
int * Real::getVal()
{
	int * pointer = &this->val;
    return pointer;
}