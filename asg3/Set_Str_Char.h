#ifndef SET_STR_CHAR_H
#define SET_STR_CHAR_H
#include "Function.h"
#include <map>
#include "common.h"
class Set_Str_Char: public Function{
public:
    //constructor
    Set_Str_Char();
    //destructor
    virtual ~Set_Str_Char();
    //sets a char at a location
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	Instructions * clone(std::vector<std::string> lines); //clone
};

#endif