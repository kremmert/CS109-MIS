#include "Get_Str_Char.h"

//constructor
Get_Str_Char::Get_Str_Char() {
}

//destructor
Get_Str_Char::~Get_Str_Char() {
	
}
//clone
Instructions * Get_Str_Char::clone(std::vector<std::string> lines){
}

//gets a char
void Get_Str_Char::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	//assigns variables
	std::string z = lines[1];
    std::string a = lines[2];
	std::string b = lines[3];

	int x = 0;
	std::string y;
	//makes sure the null character doesn't change anything
	if(mapy.find(z)== mapy.end()){
		z = z.substr(0,z.size()-1);
	}
	//gets the value of the variable
	z = mapy[z]->getV();
	
	//attempts if a number
	try{
		x = stoi(a);
	}
	catch(...)
	{
		//if not it's a variable
		x = stoi(mapy[lines[2]]->getV());
	}

	//does the same as above
	if(mapy.find(b)== mapy.end()){
		b = b.substr(0,b.size()-1);
		if(mapy.find(b)==mapy.end()){
			y = lines[3];
		}else{
			y = mapy[b]->getV();
		}
	}else{
		y = mapy[b]->getV();
	}
	
	//sets the char
	y[x]=z[0];
	mapy[b]->setVal(y);
	
}