#ifndef CHAR_H
#define CHAR_H
#include "Var.h"
#include "common.h"
#include <string.h>
class Char: public Var {
public:
	//blank constructor, data member populated later from clone function
    Char();
	//virtual destructor can delete from pointer to base class
	virtual ~Char();   
private:
	//register/container name
	std::string name;
	//tells what data type this is; for multiple types of Var in one container
    std::string type;
	//holds value, which will be a single char
    std::string val;
	
	//meant for string to do Set_Str_Char? also not curr implemented?
	//void setVal(char a);
	//getter for type name in string
	std::string getName();
	//getter for char value
	std::string getVal();
	//getter for syntax to be in unison with other Vars
	std::string getV();
    void setVal(std::string a);
	
	//allows construction of Char object to be done as a function call
	//done to allow the making of vars to be in a map of functions
	//takes parameters and converts from string when needed
	Instructions * clone(std::vector<std::string>);
	
	//works with clone to populate data fields
	Char(std::string n, std::string t, std::string v);
};

#endif