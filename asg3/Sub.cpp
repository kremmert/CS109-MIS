#include "Sub.h"
#include <exception>
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
	int x = 0;
	int y = 0;
	try{
		x = stoi(a);
	}
	catch(...)
	{
		x = stoi(mapy[lines[2]]->getV());
	}


	try{
		
		y = stoi(b);
		
	}
	catch(...)
	{
		std::string mn = lines[3];
		//std::string mn = lines[3].substr(0,lines[3].size()-1);
		if(mapy.find(mn)== mapy.end()){
			mn = mn.substr(0,mn.size()-1);
		}
/*		if(mn[mn.size()]=='\0')
		{
			std::cout <<"\n\nsubstring getting fixed";
			mn = lines[3].substr(0,lines[3].size()-1);
			//mn = lines[3].c_str();
		}*/
		y = std::stoi((mapy[mn])->getV());
	}
	
	int j = x-y;
	mapy[lines[1]]->setVal(std::to_string(j));
	std::cout<<"\n result: "<<mapy[lines[1]]->getV();
	std::cout<<"\n";

}

