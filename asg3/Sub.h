
#ifndef SUB_H
#define SUB_H
#include "Var.h"
#include "Math.h"
#include <map>
class Sub: public Math {
public:
    Sub();
    Sub(const Sub& orig);
    virtual ~Sub();
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);

private:
	void subtract(std::vector<std::string> lines);

};

#endif /* SUB_H */
