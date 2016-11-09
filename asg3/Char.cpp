#include "Char.h"
//blank basic constructor, object populated from other constructor called from clone
Char::Char(){}

//constructor to be called from clone
Char::Char(std::string n, std::string t, std::string v):name(n), type(t), val(v) {}

//destructor
Char::~Char() {}

//return data type name as string
std::string Char::getName()
{
    return this->name;
}

//function to allow Char object instantiation from map of functions
Instructions * Char::clone(std::vector<std::string> lines)
{
	//constructs object and get pointer to it
	Instructions * b = new Char(lines[1],lines[2],lines[3]);
	//returns pointer to new object
	return b;
	
}

//returns val of char
std::string Char::getVal()
{
	return this->val;
}

//doesnt need conversion but unifies syntax for generic calling
void Char::setVal(std::string a)
{
	this->val = a;
}

//doesnt need conversion but unifies syntax for generic calling
std::string Char::getV()
{
	//returns val as string
	return this->val;
}