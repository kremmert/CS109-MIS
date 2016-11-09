#include "Set_Str_Char.h"


Set_Str_Char::Set_Str_Char() {
}

Set_Str_Char::Set_Str_Char(const Set_Str_Char& orig) {
}

Set_Str_Char::~Set_Str_Char() {
	
}

Instructions * Set_Str_Char::clone(std::vector<std::string> lines){
	
}


void Set_Str_Char::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	
	std::string z = lines[1];
    std::string a = lines[2];
	std::string b = lines[3];

	int x = 0;
	std::string y;
	std::cout<<"\n here z: "<<z;
	if(mapy.find(z)== mapy.end()){
		z = z.substr(0,z.size()-1);
		
		std::cout<<"\n if ***here z: "<<z;
	}
	std::cout<<"\n end z: "<<z;
	std::cout<<"\n end z: "<<z;
	std::cout<<"\n end z: "<<z;
	z = mapy[z]->getV();
	
	try{
		x = stoi(a);
	}
	catch(...)
	{
		x = stoi(mapy[lines[2]]->getV());
	}

		
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
	
	z[x]=y[0];
	mapy[lines[1]]->setVal(z);
	std::cout<<"\n  output   "<<mapy[lines[1]]->getV();
	
}