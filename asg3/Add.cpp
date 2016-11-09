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

	int x = 0;
	int y = 0;
	int v = 2;
	while(v < lines.size())	{

		try{ 
			x = stoi(lines[v]);
		}
		catch(...) {
			x = stoi(mapy[lines[v]]->getV());
		}

		y+=x;
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
		//std::string mn = lines[v+1].substr(0,lines[v+1].size()-1);
		//std::cout<<"\n\nsubstring asldfad " << mn;
		//x = std::stoi((mapy[lines[v+1]])->getV());


		std::string mn = mapy[lines[v+1]]->getV();
		//std::string mn = lines[3].substr(0,lines[3].size()-1);
		if(mn[mn.size()]!='\0')
		{
			std::cout <<"\n\nsubstring getting fixed";
			mn = lines[v+1].substr(0,lines[v+1].size()-1);
		}
		std::cout<<"\n\nstring of the questionable location "<<lines[v+1];
		x = std::stoi((mapy[mn])->getV());
	}
	y += x;
	std::cout<<"\n\nvalue of y " << y;
	mapy[lines[1]]->setVal(std::to_string(y));
	cout<<"\n value of add:"<<mapy[lines[1]]->getV();

}

