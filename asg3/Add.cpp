#include "common.h"
using namespace std;
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

int main()
{
    long sum = add(1, 2, 3, 4);
    cout << sum << endl;
}