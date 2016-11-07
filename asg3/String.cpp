#include "String.h"
String::String(){}

String::String(std::string n, std::string t, std::string v):name(n), type(t), val(v) {}

String::~String() {}

std::string String::getName()
{
    return this->name;
}