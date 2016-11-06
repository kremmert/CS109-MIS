#include "Numeric.h"
#include "Var.h"
Numeric::Numeric(std::string n, std::string t, std::string v):name(n), type(t), val(v) {}

Numeric::~Numeric() {}

std::string getName()
{
    return name;
}