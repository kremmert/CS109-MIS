#ifndef SET_STR_CHAR_H
#define SET_STR_CHAR_H
#include "Function.h"
#include <map>
#include "common.h"
class Set_Str_Char: public Function{
public:
    Set_Str_Char();
    Set_Str_Char(const Set_Str_Char& orig);
    virtual ~Set_Str_Char();
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	Instructions * clone(std::vector<std::string> lines);
};

#endif