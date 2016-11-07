
#ifndef SUB_H
#define SUB_H
#include "Var.h"
#include "Math.h"
class Sub: public Math {
public:
    Sub();
    Sub(const Sub& orig);
    virtual ~Sub();
private:
	void subtract(Var * a, int par1, int par2);

};

#endif /* SUB_H */
