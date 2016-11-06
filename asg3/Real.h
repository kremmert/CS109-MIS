#include "var.h"
class Real:Var {
public:
    Real(std::string n, std::string t, int v);
    virtual ~Real();
    std::string getName();
private:
    std::string name;
    std::string type;
    std::string val;
    int num;

};
