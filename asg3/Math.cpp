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

   if(as.empty() || ((!isdigit(as[0])) && (as[0] != '-') && (as[0] != '+'))) return false ;

   char * p ;
   std::strtol(as.c_str(), &p, 10) ;

   return (*p == 0) ;
}
