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
	std::cout << "THIS IS A NULL PTR PROBABLY: "<<mapy[lines[3]];
	std::cout << "\n is this a num: (a) = "<<isnum(a);
	std::cout << "\n\nis this a num: (b) ="<<isnum(b);
	std::cout << "\n\nlines[3]**********"<<mapy[lines[1]];
	int x,y;
	
	for (std::map<std::string,Instructions*>::iterator it=mapy.begin(); it!=mapy.end(); ++it)
		std::cout <<"\n"<< it->first << " => " << it->second << '\n';

	try{
		x = stoi(a);
	}
	catch(...)
	{
		x = stoi(mapy[lines[2]]->getV());
	}

/*	if(isnum(a)){
		x = stoi(a);
	}else{
		x = stoi(mapy[lines[2]]->getV());
	}*/

	try{
		std::cout << "\n lines[3]****444*****"<<mapy[lines[1]]<<lines[1];
		std::cout << "\n lines[3]****4*****"<<mapy[lines[3]]<<lines[3]<<"   "<<lines[3].substr(0,lines[3].size()-1);
		if(lines[1].compare(lines[3].substr(0,lines[3].size()-1))==0){
			std::cout<<"\n they are the same!";
		}
		
		std::cout << "\n lines[3]****444*****"<<mapy[lines[1]]<<lines[1];
		std::cout << "\n lines[3]****4*****"<<mapy[lines[3]]<<lines[3];
		y = stoi(b);
		
		std::cout << "\n\nlines[3]*****5****"<<mapy[lines[3]];
		
	}
	catch(...)
	{
		std::cout << "\n\nlines[3]**********"<<mapy[lines[3]];
		std::string mn = lines[3].substr(0,lines[3].size()-1);
		y = std::stoi((mapy[mn])->getV());
	}
/*	if(isnum(b)){
		y = stoi(b);
	}else{
		y = stoi(mapy[lines[3]]->getV());
	}*/
	int j = x-y;
	std::cout << "\n\nlines[123]**********"<<mapy[lines[1]];
	mapy[lines[1]]->setVal(std::to_string(j));
	
	std::cout << "\n" <<mapy[lines[1]]->getV() << "\n";
	std::cout << "\n\nlines[45]**********"<<mapy[lines[1]];
}

