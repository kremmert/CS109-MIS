#include "String.h"

String::String(){}

String::String(std::string n, std::string t, std::string v):name(n), type(t), val(v) {}

String::~String() {}

std::string String::getName()
{
    return this->name;
}

Instructions * String::clone(std::vector<std::string> lines){
	Instructions * b = new String(lines[1],lines[2],lines[4]);
	return b;
	
}

std::string String::getVal()
{
	return this->val;
}

void String::setVal(std::string a)
{
	this->val = a;
}

std::string String::getV()
{
	return this->val;
}
