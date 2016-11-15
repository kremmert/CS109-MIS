#include "Div.h"
#include "common.h"

//constructor
Div::Div() {
}
//destructor
Div::~Div() {
}

//divides the second element with the third
void Div::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
    //initialize variables
	std::string a = lines[2];
	std::string b = lines[3];
	double x = 0;
	double y = 0;
	
	//attempt to turn the first string into an int
	try{
		x = stod(a);
	}
	catch(...)
	{	//if that fails, get the value of the variable
		x = stod(mapy[lines[2]]->getV());
	}

	//same as above
	try{
		
		y = stod(b);
		
	}
	catch(...)
	{
		std::string mn = lines[3];
		//a check if the last element has a null character which will
		//make the string not equal to the one stored in the map

		y = std::stod((mapy[mn])->getV());
	}
	//make sure you aren't dividing by zero'
	if(y==0){
		std::cout<<" Divide by zero";
		return;
	}
	//the divide
	double j = x/y;
	mapy[lines[1]]->setVal(std::to_string(j));
}

