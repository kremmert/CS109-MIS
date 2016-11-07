#include "common.h"
#include "Mul.h"
using namespace std;
template<typename T>
T mul(T a)
{
    return a;
}

template<typename T, typename... num>
T multiply(T res, num... args)
{
    return res * mul(args...);
}
