#ifndef ADD_H
#define ADD_H
#include "Math.h"
#include <map>
class Add: public Math {
public:
    //constructor
    Add();
    //destructor
    virtual ~Add();
    //function that adds up an instruction
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
	
private:


};

#endif