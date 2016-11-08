
#ifndef DIV_H
#define DIV_H
#include "Math.h"
#include <map>
class Div: public Math {
public:
    Div();
    Div(const Div& orig);
    virtual ~Div();
	void divide(int, int, int );
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:


};

#endif /* DIV_H */
