#include "common.h"
using namespace std;
template<typename T>
T mul(T a)
{
    return a;
}

template<typename T, typename... num>
T mul(T res, num... args)
{
    return res * mul(args...);
}

int main()
{
    long sum = mul(1, 2, 3, 4);
    cout << sum << endl;
}