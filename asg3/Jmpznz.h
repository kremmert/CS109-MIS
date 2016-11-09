#ifndef Jmpznz_H
#define Jmpznz_H
#include "Jmp.h"
#include <map>
#include "common.h"
class Jmpznz: public Jmp{
public:
    Jmpznz();
    Jmpznz(const Jmpznz& orig);
    virtual ~Jmpznz();
	virtual void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	Instructions * clone(std::vector<std::string> lines);
};

#endif