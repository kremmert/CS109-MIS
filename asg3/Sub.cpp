#include "Sub.h"

Sub::Sub() {
}

Sub::Sub(const Sub& orig) {
}

Sub::~Sub() {
}
//Subtract the third parameter from the second parameter and store the result in the first parameter
void Sub::subtract(std::vector<std::string> lines){
    //int * b = a->getVal();
	//*b = par1 - par2;
	

}


void Sub::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){


    std::string a = lines[2];
	std::string b = lines[3];
	

	if(isnum(a)){
		a = stoi(a);
	}else{
		a = mapy[lines[2]]->getVal();
	}
	
	if(isnum(b)){
		b = stoi(b);
	}else{
		b = mapy[lines[3]]->getVal();
	}
	
	mapy[lines[1]]->val = a-b;
	
}

