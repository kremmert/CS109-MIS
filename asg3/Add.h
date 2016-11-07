
#include "Math.h"
class Add: public Math {
public:
    Add();
    Add(const Add& orig);
    virtual ~Add();
private:
	template<typename T, typename... num>
    T add(T res, num... args);


};
