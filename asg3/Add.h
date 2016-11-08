#ifndef ADD_H
#define ADD_H
#include "Math.h"
#include <map>
class Add: public Math {
public:
    Add();
    Add(const Add& orig);
    virtual ~Add();
	void functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy);
private:
	template<typename T, typename... num>
    T add(T res, num... args);


};

#endif