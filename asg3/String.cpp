#include "String.h"

String::String(){}

String::String(std::string n, std::string t, std::string v):name(n), type(t), val(v) {}

String::~String() {}

std::string String::getName()
{
    return this->name;
}

Var * String::clone(std::vector<std::string> lines){
	Var * b = new String(lines[1],lines[2],lines[4]);
	return b;
	
}