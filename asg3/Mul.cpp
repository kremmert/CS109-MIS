#include "common.h"
#include "Mul.h"
using namespace std;

//constructor
Mul::Mul()
{
	
}

//destructor
Mul::~Mul()
{

}

//multiplying function
void Mul::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	//get first variable and set others
	std::string a = lines[2];

	double x = 0;
	double y = 1;
	int v = 2;
	while(v < lines.size())	{
		//attempt to change string to number
		try{ 
			x = stod(lines[v]);
		}
		catch(...) {
		//if not check for value of variable
			x = stod(mapy[lines[v]]->getV());
		}
		//multiply together
		y*=x;
		//break when vector is empty
		if(lines[v+2].compare("")==0)
		{
			break;
		}

		v++;
	}
	x = 0;

	//checks if last element is in map because null character
	//basically does same as above
	try{
		
		x = stoi(lines[v+1]);
		
	}
	catch(...)
	{
		
		std::string mn = lines[v+1];

		if(mapy.find(mn)== mapy.end()){
			mn = mn.substr(0,mn.size()-1); //removes null character to match up
		}
	x = std::stoi((mapy[mn])->getV());
	}
	y *= x; //multiply
	//sets the value
	mapy[lines[1]]->setVal(std::to_string(y));
}