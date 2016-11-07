
#ifndef DIV_H
#define DIV_H
#include "Math.h"
class Div: public Math {
public:
    Div();
    Div(const Div& orig);
    virtual ~Div();
private:
	void divide(int, int, int );

};

#endif /* DIV_H */
