
#ifndef SUB_H
#define SUB_H
#include "Var.h"
#include "Math.h"
#include <map>
class Sub: public Math {
public:
	//sub constructor
    Sub();
	//sub copy constructor
    Sub(const Sub& orig);
	//sub destructor
    virtual ~Sub();
	//functor: does the subtraction operation get args from lines and vars from mapy
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);

private:

};

#endif /* SUB_H */
