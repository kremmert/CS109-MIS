#include "Var.h"
#include "common.h"
#include <string.h>
#include "Numeric.h"
#include "Real.h"
#include "Char.h"
#include "String.h"
Var::Var() {
}

Var::Var(const Var& orig) {
}

Var::~Var() {
}

Var * Var::decode(std::vector<std::string> lines)
{/*
    Var * v  = nullptr;
    varType = lines[0];
    name = lines[1];
    type = lines[2];
    if(lines.size() == 5)
    {
        num = std::stoi(lines[3]);
        val = lines[4];
    }
    if(name.compare("CHAR"))
    {
        val = lines[3];
    }
    if(name.compare("NUMERIC") || name.compare("REAL"))
    {    
        num = std::stoi(lines[3]);
    }
    if(name.compare("NUMERIC"))
    {
        v = new Numeric(name,type,num);
    }
    
    if(name.compare("REAL"))
    {
        v = new Real(name,type,num);
    }

    if(name.compare("CHAR"))
    {
        v = new Char(name,type,val);
    }

    if(name.compare("STRING"))
    {
        v = new String(name,type,val);
    }    

    return v;
	*/
}

std::string Var::getName()
{
    return name;
}