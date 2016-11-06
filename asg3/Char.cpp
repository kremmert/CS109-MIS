#include "Char.h"
Char::Char(std::string n, std::string t, std::string v):name(n), type(t), val(v) {}

Char::~Char() {}

std::string Char::getName()
{
    return this->name;
}