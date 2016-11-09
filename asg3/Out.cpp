#include "Out.h"
#include <iostream>
#include <fstream>


Out::Out() {
}

Out::Out(const Out& orig) {
}

Out::~Out() {
	
}

Instructions * Out::clone(std::vector<std::string> lines){
	
}


void Out::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){

	std::ofstream outputFile;;
	outputFile.open("Output.out");
	
	std::string mn;
	for(int x = 1; x <lines.size()-1;x++){
		if(lines[x].compare("")==0) break;
		mn = lines[x];
		
		if(mapy.find(mn)== mapy.end()){
			mn = mn.substr(0,mn.size()-1);
			if(mapy.find(mn)==mapy.end()){
				outputFile<<"Arg: "<<lines[x]<<std::endl;
				continue;
			}
		}

		outputFile<<"Arg: "<<mn<<"    Val::"<<mapy[mn]->getV()<<std::endl;
	}
	
	outputFile.close();
	
	
}