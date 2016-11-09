#ifndef MATH_H
#define MATH_H
#include "Function.h"
#include <map>
class Math: public Function{
public:
    //constructor
    Math();
    //destructor
    virtual ~Math();
    //pure virtual method so subclasses have functions to perform
    //this allows us to easily call everything from an Instructions vector
	virtual void functor(std::vector<std::string>,std::map <std::string,Instructions *> & mapy) = 0;
	virtual bool isnum(std::string &); //checks if a std::string is a number
private:
	Instructions * clone(std::vector<std::string> lines); //clone
    


};
#endif