#include "common.h"
#include "Add.h"
using namespace std;
Add::Add()
{

}

Add::Add(const Add& orig)
{

}


Add::~Add()
{

}

template<typename T>
T add(T a)
{
    return a;
}

template<typename T, typename... num>
T add(T res, num... args)
{
    return res + add(args...);
}
