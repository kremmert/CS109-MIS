
#ifndef SUB_H
#define SUB_H
#include "Var.h"
#include "Math.h"
class Sub: public Math {
public:
    Sub();
    Sub(const Sub& orig);
    virtual ~Sub();
	void functor(std::vector<std::string>);
private:
	void subtract(std::vector<std::string> lines);

};

#endif /* SUB_H */
