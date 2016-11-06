#include "var.h"
Var::Var() {
}

Var::Var(const Var& orig) {
}

Var::~Var() {
}

void Var::decode(std::vector<std::string> lines)
{
    varType = lines[0];
    name = lines[1];
    type = lines[2];
    if(lines.size() == 5)
    {
        num = std::stoi(lines[3]);
        val = lines[4];
    }
    else
        num = std::stoi(lines[3]);
    
    if(name.compare("NUMERIC"))
    {

    }
    
    if(name.compare("REAL"))
    {

    }

    if(name.compare("CHAR"))
    {

    }

    if(name.compare("STRING"))
    {

    }    
}