#include "Math.h"

Math::Math() {
}

Math::Math(const Math& orig) {
}

Math::~Math() {
}

Instructions * Math::clone(std::vector<std::string>){

	}
	
bool Math::isnum(std::string & as){
	return !as.empty() &&std::find_if(as.begin(), as.end(),[](char c){return !std::isdigit(c);})==as.end();
}