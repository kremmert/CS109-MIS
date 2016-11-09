#ifndef STRING_H
#define STRING_H
#include "Var.h"
#include "common.h"
#include <string.h>
class String: public Var {
public:
	//blank constructor, data member populated later from clone function
    String();
	//virtual destructor can delete from pointer to base class
    virtual ~String();    	
private:
	//register/container name
	std::string name;
	//tells what data type this is; for multiple types of Var in one container
    std::string type;
	//Holds value, is a string which is an array of chars
    std::string val;
	//holds size of char array
	int num;
	
	void setVal(std::string a);
	//getter for type name in string
	std::string getName();
	//getter for string value 
	std::string getVal();
	//getter for syntax to be in unison with other Vars
	std::string getV();
	
	//allows construction of String object to be done as a function call
	//done to allow the making of vars to be in a map of functions
	//takes parameters and converts from string when needed
	String(std::string n, std::string t, std::string v);	
	
	//takes parameters and converts from string when needed
	Instructions * clone(std::vector<std::string>);    
};
#endif