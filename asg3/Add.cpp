#include "common.h"
#include "Add.h"
using namespace std;
Add::Add()
{

}

Add::~Add()
{

}


void Add::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){

	std::string a = lines[2];//first number to be added

	double x = 0;
	double y = 0;
	int v = 2;
	//while we go through parameters
	while(v < lines.size())	{

		try{ 
			//try to conver to int
			x = stod(lines[v]);
		}
		catch(...) {
			//else get the string from object then convert to int
			x = stod(mapy[lines[v]]->getV());
		}
		
		//add the number to itself
		y+=x;
		//if the next param is empty break
		if(lines[v+1].compare("")==0)
		{
			break;
		}

		v++;
	}

	mapy[lines[1]]->setVal(std::to_string(y));
}

