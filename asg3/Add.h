#ifndef ADD_H
#define ADD_H
#include "Math.h"
class Add: public Math {
public:
    Add();
    Add(const Add& orig);
    virtual ~Add();
	void functor(std::vector<std::string>);
private:
	template<typename T, typename... num>
    T add(T res, num... args);


};

#endif