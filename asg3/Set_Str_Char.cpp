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
	//checks if null character doesn't mess anything up
	if(mapy.find(z)== mapy.end()){
		z = z.substr(0,z.size()-1);
	}
	//gets the value of the variable
	z = mapy[z]->getV();
	
	//checks if the next input is a number
	try{
		x = stoi(a);
	}
	catch(...)
	{
		//if not get the value from the variable
		x = stoi(mapy[lines[2]]->getV());
	}

	//checks once again because null character
	if(mapy.find(b)== mapy.end()){
		b = b.substr(0,b.size()-1);
		if(mapy.find(b)==mapy.end()){
			y = lines[3]; //assigns
		}else{
			y = mapy[b]->getV();
		}
	}else{
		y = mapy[b]->getV();
	}
	//sets the char 
	z[x]=y[0];
	mapy[lines[1]]->setVal(z);
	
}