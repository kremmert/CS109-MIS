#include "Numeric.h"
//blank basic constructor, object populated from other constructor called from clone
Numeric::Numeric(){}

//constructor to be called from clone
Numeric::Numeric(std::string n, std::string t, int v):name(n), type(t), val(v) {}

//destructor
Numeric::~Numeric() {}

//return data type name as string
std::string Numeric::getName()
{
    return this->name;
}

//takes a string and converts to integer in order to set val data member
void Numeric::setVal(std::string a)
{
	this->val = std::stoi(a);
}

//returns pointer to val
int * Numeric::getVal()
{
	//puts reference to val in a pointer
	int * pointer = &this->val;
	//return the pointer
    return pointer;
}

//function to allow Numeric object instantiation from map of functions
Instructions * Numeric::clone(std::vector<std::string> lines)
{
	//constructs object and get pointer to it
	Instructions * b = new Numeric(lines[1],lines[2],stoi(lines[3]));
	//returns pointer to new object
	return b;
	
}

//gets value as a string
std::string Numeric::getV()
{
	//convert val to string and return
	return std::to_string(val);
}