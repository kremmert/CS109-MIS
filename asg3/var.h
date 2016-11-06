#include "common.h"
#include <stdlib.h>
class Var {
public:
    Var();
    Var(const Var& orig);
    virtual ~Var();
    virtual std::string getName() = 0;
    void decode(std::vector<std::string> lines);
private:
    std::string varType;
    std::string name;
    std::string type;
    std::string val;
    int num;

};
