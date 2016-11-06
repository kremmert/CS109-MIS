#include "var.h"
class Numeric:Var {
public:
    Numeric(std::string n, std::string t, std::string v);
    virtual ~Numeric();
    std::string getName();
private:
    std::string name;
    std::string type;
    std::string val;
    int num;

};
