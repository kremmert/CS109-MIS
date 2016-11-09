#include "Real.h"
//blank basic constructor, object populated from other constructor called from clone
Real::Real(){}

//constructor to be called from clone
Real::Real(std::string n, std::string t, double v):name(n), type(t), val(v) {}

//destructor
Real::~Real() {}

//return data type name as string
std::string Real::getName()
{
    return this->name;
}

//function to allow Real object instantiation from map of functions
Instructions * Real::clone(std::vector<std::string> lines)
{
	//constructs object and get pointer to it
	Instructions * b = new Real(lines[1],lines[2],stoi(lines[3]));
	//returns pointer to new object
	return b;
	
}

//returns pointer to val
double * Real::getVal()
{
	//puts reference to val in a pointer
	double * pointer = &this->val;
	//return that pointer
    return pointer;
}

//gets value as a string
std::string Real::getV()
{
	//convert to string and return
	return std::to_string(this->val);
}

//takes a string and converts it in order to set val data member
void Real::setVal(std::string a)
{
	//convert and set data member
	val = std::stod(a);
}