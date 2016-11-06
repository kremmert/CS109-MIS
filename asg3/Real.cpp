#include "Real.h"
Real::Real(std::string n, std::string t, int v):name(n), type(t), num(v) {}

Real::~Real() {}

std::string Real::getName()
{
    return this->name;
}