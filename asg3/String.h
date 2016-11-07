#ifndef STRING_H
#define STRING_H
#include "Var.h"
#include "common.h"
#include <string.h>
class String: public Var {
public:
    String();
    String(std::string n, std::string t, std::string v);
    virtual ~String();
    std::string getName();
	int * getVal();
	Var * clone(std::vector<std::string>);
private:
    std::string name;
    std::string type;
    std::string val;
    int num;

};
#endif