#include "Numeric.h"
Numeric::Numeric(std::string n, std::string t, std::string v):name(n), type(t), val(v) {}

Numeric::~Numeric() {}

std::string Numeric::getName()
{
    return this->name;
}