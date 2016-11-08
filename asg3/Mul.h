#ifndef MUL_H
#define MUL_H
#include "Math.h"
#include <map>
class Mul: public Math {
public:
    Mul();
    Mul(const Mul& orig);
    virtual ~Mul();
	
	template<typename T, typename... num>
    T multiply(T res, num... args);
	void functor(std::vector<std::string> ,std::map <std::string,Instructions *> & mapy);
private:


};

#endif