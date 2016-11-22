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

std::vector<std::string> Out::outputV(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	std::vector<std::string> temp(50);
//	std::ofstream outputFile;;
//	outputFile.open("Output.out",std::ios::app);//make file called Output.out
	
	std::string mn;
	for(int x = 1; x <lines.size()-1;x++){
		if(lines[x].compare("")==0) break;//if empty arg break
		mn = lines[x];
		//mn equals arg
		if(mapy.find(mn)==mapy.end()){
			temp[x] = lines[x];//it was a constant, print
			continue;
		}
		
		//print var
		std::cout<<"Arg: "<<mn<<"    Val::"<<mapy[mn]->getV()<<std::endl;
		temp[x] = mapy[mn]->getV();
	}
	//close file
//	outputFile.close();
	
	return temp;
}

//prints args to a file called Output.out
void Out::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){

	std::ofstream outputFile;;
	outputFile.open("Output.out",std::ios::app);//make file called Output.out
	
	std::string mn;
	for(int x = 1; x <lines.size()-1;x++){
		if(lines[x].compare("")==0) break;//if empty arg break
		mn = lines[x];
		//mn equals arg
		if(mapy.find(mn)==mapy.end()){
			outputFile<<"Arg: "<<lines[x]<<std::endl;//it was a constant, print
			continue;
		}
		
		//print var
		outputFile<<"Arg: "<<mn<<"    Val::"<<mapy[mn]->getV()<<std::endl;
	}
	//close file
	outputFile.close();
	
	
}