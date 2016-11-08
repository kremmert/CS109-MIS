#include "Math.h"

Math::Math() {
}

Math::Math(const Math& orig) {
}

Math::~Math() {
}

Instructions * Math::clone(std::vector<std::string>){

	}
	
inline bool Math::isnum(std::string & as){
	//return !as.empty() &&std::find_if(as.begin(), as.end(),[](char c){return !std::isdigit(c);})==as.end();

	//return std::all_of(as.begin(), as.end(), ::isdigit);

   if(as.empty() || ((!isdigit(as[0])) && (as[0] != '-') && (as[0] != '+'))) return false ;

   char * p ;
   std::strtol(as.c_str(), &p, 10) ;

   return (*p == 0) ;
}
