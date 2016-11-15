#include "Assign.h"


Assign::Assign() {
}

Assign::Assign(const Assign& orig) {
}

Assign::~Assign() {
	
}

Instructions * Assign::clone(std::vector<std::string> lines){
	
}


void Assign::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
//	std::string a = lines[1];
	std::string b = lines[2];

//	int x = 0;
	int y = 0;

	try{
		
		y = stod(b);
		
	}
	catch(...)
	{
		std::string mn = lines[2];
		//a check if the last element has a null character which will
		//make the string not equal to the one stored in the map

		y = std::stod((mapy[lines[2]])->getV());
	}

	mapy[lines[1]]->setVal(std::to_string(y));
	
	
}