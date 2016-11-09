#include "String.h"
//blank basic constructor, object populated from other constructor called from clone
String::String(){}

//constructor to be called from clone
String::String(std::string n, std::string t, std::string v):name(n), type(t), val(v) {}

//destructor
String::~String() {}

//return data type name as string
std::string String::getName()
{
    return this->name;
}

//function to allow string object instantiation from map of functions
Instructions * String::clone(std::vector<std::string> lines)
{
	//constructs object and get pointer to it
	Instructions * b = new String(lines[1],lines[2],lines[4]);
	//returns pointer to new object
	return b;
	
}

//return val of String
std::string String::getVal()
{
	return this->val;
}

//doesnt need conversion but unifies syntax for generic calling
void String::setVal(std::string a)
{
	this->val = a;
}

//doesnt need conversion but unifies syntax for generic calling
std::string String::getV()
{
	//return val as string
	return this->val;
}
