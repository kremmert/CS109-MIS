#include "Sleep.h"
#include <unistd.h>
#include <chrono>
#include <thread>

Sleep::Sleep() {
}

Sleep::Sleep(const Sleep& orig) {
}

Sleep::~Sleep() {
	
}

Instructions * Sleep::clone(std::vector<std::string> lines){
	
}


void Sleep::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	std::string a = lines[1];

	int x = 0;
	try{
		x = stoi(a);
	}
	catch(...)
	{
		
		std::string mn = lines[1];
		if(mapy.find(mn)== mapy.end()){
			mn = mn.substr(0,mn.size()-1);
		}
		x = stoi(mapy[mn]->getV());
	}
	//sleep for x seconds
	std::this_thread::sleep_for(std::chrono::milliseconds(x*1000));
	
}