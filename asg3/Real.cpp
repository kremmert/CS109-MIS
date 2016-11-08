#include "Real.h"
Real::Real(){}

Real::Real(std::string n, std::string t, double v):name(n), type(t), val(v) {}

Real::~Real() {}

std::string Real::getName()
{
    return this->name;
}

Instructions * Real::clone(std::vector<std::string> lines){
	Instructions * b = new Real(lines[1],lines[2],stoi(lines[3]));
	return b;
	
}
double * Real::getVal()
{
	double * pointer = &this->val;
    return pointer;
}
