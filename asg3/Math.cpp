#include "Math.h"
//constructor
Math::Math() {
}
//destuctor
Math::~Math() {
}
//clone
Instructions * Math::clone(std::vector<std::string>){

	}
	
inline bool Math::isnum(std::string & as){
    //iterates through a string and checks for digits
   if(as.empty() || ((!isdigit(as[0])) && (as[0] != '-') && (as[0] != '+'))) return false ;

   char * p ;
   std::strtol(as.c_str(), &p, 10) ;
   //returns if the string is a number
   return (*p == 0) ;
}
