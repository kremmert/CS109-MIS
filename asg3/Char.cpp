#include "Char.h"

Char::Char(){}

Char::Char(std::string n, std::string t, std::string v):name(n), type(t), val(v) {}

Char::~Char() {}

std::string Char::getName()
{
    return this->name;
}

Instructions * Char::clone(std::vector<std::string> lines){
	Instructions * b = new Char(lines[1],lines[2],lines[3]);
	return b;
	
}

std::string Char::getVal()
{
	return this->val;
}

void Char::setVal(char a)
{
	val = a;
}