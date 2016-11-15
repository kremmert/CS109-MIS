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

		
/*	std::string mn = lines[2];
	if(mapy.find(mn)== mapy.end()){
		mn = mn.substr(0,mn.size()-1);
	}
	x = stoi(mapy[mn]->getV());
*/

	try{
		
		y = stod(b);
		
	}
	catch(...)
	{
		std::string mn = lines[2];
		//a check if the last element has a null character which will
		//make the string not equal to the one stored in the map
		if(mapy.find(mn)== mapy.end()){
			mn = mn.substr(0,mn.size()-1);
		}

		y = std::stod((mapy[mn])->getV());
	}

	mapy[lines[1]]->setVal(std::to_string(y));
	
	
}