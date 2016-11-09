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
	std::string a = lines[1];
	std::string b = lines[2];

	int x = 0;
	int y = 0;

		
	std::string mn = lines[2];
	if(mapy.find(mn)== mapy.end()){
		mn = mn.substr(0,mn.size()-1);
	}
	x = stoi(mapy[mn]->getV());

	mapy[lines[1]]->setVal(std::to_string(x));

	
	
	
}