#include "Sub.h"
#include <exception>
Sub::Sub() {
}

Sub::Sub(const Sub& orig) {
}

Sub::~Sub() {
}


//Subtract the third parameter from the second parameter and store the result in the first parameter

void Sub::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){

    std::string a = lines[2];// arg 1,constant or var
	std::string b = lines[3];//arg 2, constant or var
	std::cout<<"\n var name"<<lines[3];
	int x = 0;
	int y = 0;
	//try to convert to int
	try{
		//to see if constant or var
		x = stoi(a);
		//this is a constant
	}
	catch(...)
	{	//this is var
		x = stoi(mapy[lines[2]]->getV());
	}


	try{
		//this is constant
		y = stoi(b);
		
	}
	catch(...)
	{
		//this is a var
		
		y = std::stoi((mapy[lines[3]])->getV());
	}
	//the actual subtraction
	int j = x-y;
	//seting the value
	mapy[lines[1]]->setVal(std::to_string(j));


}

