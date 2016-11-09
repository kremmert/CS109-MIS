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
	std::string a = lines[2];

	int x = 0;
	int y = 1;
	int v = 2;
	while(v < lines.size())	{

		try{ 
			x = stoi(lines[v]);
		}
		catch(...) {
			x = stoi(mapy[lines[v]]->getV());
		}

		y*=x;
		if(lines[v+2].compare("")==0)
		{
			break;
		}

		v++;
	}
	x = 0;

	try{
		
		x = stoi(lines[v+1]);
		
	}
	catch(...)
	{
		
		std::string mn = lines[v+1];

		if(mapy.find(mn)== mapy.end()){
			mn = mn.substr(0,mn.size()-1);
		}
	x = std::stoi((mapy[mn])->getV());
	}
	y *= x;
	
	mapy[lines[1]]->setVal(std::to_string(y));
	cout<<"\n value of mul:"<<mapy[lines[1]]->getV();
}