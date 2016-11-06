#include "var.h"
class Char:Var {
public:
    Char(std::string n, std::string t, val v);
    virtual ~Char();
    std::string getName();
private:
    std::string name;
    std::string type;
    std::string val;
    int num;

};
