#include "Numeric.h"
Numeric::Numeric(){}

Numeric::Numeric(std::string n, std::string t, int v):name(n), type(t), num(v) {}

Numeric::~Numeric() {}

std::string Numeric::getName()
{
    return this->name;
}

Var * Numeric::clone(std::vector<std::string> lines){
	Var * b = new Numeric(lines[1],lines[2],stoi(lines[3]));
	return b;
	
}