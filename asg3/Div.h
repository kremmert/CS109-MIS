
#ifndef DIV_H
#define DIV_H
#include "Math.h"
class Div: public Math {
public:
    Div();
    Div(const Div& orig);
    virtual ~Div();
	void divide(int, int, int );
	void functor(std::vector<std::string>);
private:


};

#endif /* DIV_H */
