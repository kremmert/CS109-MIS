#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H


#include "common.h"

class Instructions {
public:
    Instructions();
    Instructions(const Instructions& orig);
    virtual ~Instructions();
	virtual Instructions * clone(std::vector<std::string>) = 0;
private:
    



};
#endif