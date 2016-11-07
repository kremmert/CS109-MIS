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
        Var v = new Numeric(name,type,num);
    }
    
    if(name.compare("REAL"))
    {
        Var v = new Real(name,type,num);
    }

    if(name.compare("CHAR"))
    {
        Var v = new Char(name,type,val);
    }

    if(name.compare("STRING"))
    {
        Var v = new String(name,type,val);
    }    
}