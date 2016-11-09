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


void Add::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){

	std::string a = lines[2];//first number to be added

	int x = 0;
	int y = 0;
	int v = 2;
	//while we go through parameters
	while(v < lines.size())	{

		try{ 
			//try to conver to int
			x = stoi(lines[v]);
		}
		catch(...) {
			//else get the string from object then convert to int
			x = stoi(mapy[lines[v]]->getV());
		}
		
		//add the number to itself
		y+=x;
		//if the next param is empty break
		if(lines[v+2].compare("")==0)
		{
			break;
		}

		v++;
	}
	x = 0;
	//edge case for ending null char
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
	
	y += x;
	
	mapy[lines[1]]->setVal(std::to_string(y));
	cout<<"\n value of add:"<<mapy[lines[1]]->getV();

}

