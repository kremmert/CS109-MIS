#include "var.h"
class String:Var {
public:
    String(std::string n, std::string t, val v);
    virtual ~String();
    std::string getName();
private:
    std::string name;
    std::string type;
    std::string val;
    int num;

};
