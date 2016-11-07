#ifndef CHAR_H
#define CHAR_H
#include "var.h"
#include "common.h"
#include <string.h>
class Char: public Var {
public:
    Char();
    Char(std::string n, std::string t, std::string v);
    virtual ~Char();
    std::string getName();
private:
    std::string name;
    std::string type;
    std::string val;
    int num;

};

#endif