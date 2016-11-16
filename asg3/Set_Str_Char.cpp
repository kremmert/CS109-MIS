#include "Set_Str_Char.h"

//constructor
Set_Str_Char::Set_Str_Char() {
}

//destructor
Set_Str_Char::~Set_Str_Char() {
	
}

//clone
Instructions * Set_Str_Char::clone(std::vector<std::string> lines){
	
}

//sets a char to a location indexed
void Set_Str_Char::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	
	//gets variables
	std::string z = lines[1];
    std::string a = lines[2];
	std::string b = lines[3];

	int x = 0;
	std::string y;

	//gets the value of the variable
	z = mapy[z]->getV();
	
	//checks if the next input is a number
	try{
		x = stod(a);
	}
	catch(...)
	{
		//if not get the value from the variable
		x = stod(mapy[lines[2]]->getV());
	}

	//checks once again because null character
	
	if(mapy.find(b)==mapy.end()){
		y = lines[3]; //assigns
	}else{
		y = mapy[b]->getV();
	}

	//sets the char 
	z[x]=y[1];
	mapy[lines[1]]->setVal(z);
	
}