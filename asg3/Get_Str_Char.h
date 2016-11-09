#ifndef GET_STR_CHAR_H
#define GET_STR_CHAR_H
#include "Function.h"
#include <map>
#include "common.h"
class Get_Str_Char: public Function{
public:
    //constructor
    Get_Str_Char();
    //destructor
    virtual ~Get_Str_Char();
    //function that gets a char at a location and places it elsewhere
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	Instructions * clone(std::vector<std::string> lines); //clone
};

#endif