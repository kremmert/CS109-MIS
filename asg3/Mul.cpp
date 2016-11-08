#include "common.h"
#include "Mul.h"
using namespace std;
Mul::Mul()
{
	
}

Mul::Mul(const Mul& orig)
{

}

Mul::~Mul()
{

}

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

void Mul::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	std::cout<<"           ";
}