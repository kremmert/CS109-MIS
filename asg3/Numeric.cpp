#include "Numeric.h"
Numeric::Numeric(){}

Numeric::Numeric(std::string n, std::string t, int v):name(n), type(t), val(v) {}

Numeric::~Numeric() {}

std::string Numeric::getName()
{
    return this->name;
}

void Numeric::setVal(int a)
{
	val = a;
}

int * Numeric::getVal()
{
	int * pointer = &this->val;
    return pointer;
}
Instructions * Numeric::clone(std::vector<std::string> lines){
	Instructions * b = new Numeric(lines[1],lines[2],stoi(lines[3]));
	return b;
	
}