#ifndef VAR_H
#define VAR_H
#include "Numeric.h"
#include "Real.h"
#include "Char.h"
#include "String.h"
#include "common.h"
#include <stdlib.h>
class Var {
public:
    Var();
    Var(const Var& orig);
    virtual ~Var();
    virtual std::string getName();
    Var * decode(std::vector<std::string> lines);
private:
    std::string varType;
    std::string name;
    std::string type;
    std::string val;
    int num;

};

#endif