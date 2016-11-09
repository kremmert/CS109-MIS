#ifndef MUL_H
#define MUL_H
#include "Math.h"
#include <map>
class Mul: public Math {
public:
    //constructor
    Mul();
    //destructor
    virtual ~Mul();
	//function for multiplying
	void functor(std::vector<std::string> ,std::map <std::string,Instructions *> & mapy);
private:


};

#endif