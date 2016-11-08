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

void Add::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	std::cout<<"\n help me";
	std::string a = lines[2];

	int x,y;
	int v = 2;
	while(2<lines.size()){
		if(isnum(a)){
			x = stoi(a);
		}else{
			x = stoi(mapy[lines[2]]->getV());
		}
		y += x;
	}
	
	mapy[lines[1]]->setVal(std::to_string(y));
	cout<<"\n value of add:"<<mapy[lines[1]]->getV();

}

