#include "Numeric.h"
Numeric::Numeric(){}

Numeric::Numeric(std::string n, std::string t, int v):name(n), type(t), num(v) {}

Numeric::~Numeric() {}

std::string Numeric::getName()
{
    return this->name;
}