#include "Out.h"


Out::Out() {
}

Out::Out(const Out& orig) {
}

Out::~Out() {
	
}

Instructions * Out::clone(std::vector<std::string> lines){
	
}


void Out::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){


	std::string mn;
	for(int x = 1; x <lines.size()-1;x++){
		if(lines[x].compare("")==0) break;
		mn = lines[x];
		
		if(mapy.find(mn)== mapy.end()){
			mn = mn.substr(0,mn.size()-1);
			if(mapy.find(mn)==mapy.end()){
				std::cout<<"\nArg: "<<lines[x];
				continue;
			}
		}

		std::cout<<"\nArg: "<<mn<<"    Val::"<<mapy[mn]->getV();
	}
	
	
}