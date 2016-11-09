#ifndef LABEL_H
#define LABEL_H
#include "Function.h"
#include <map>
#include "common.h"
class Label: public Function{
public:
    Label();
    Label(const Label& orig);
    virtual ~Label();
	virtual void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	Instructions * clone(std::vector<std::string> lines);
};

#endif