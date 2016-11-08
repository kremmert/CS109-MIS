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
	std::cout << "THIS IS A NULL PTR PROBABLY: "<<lines[3]<< "end";
	std::cout << "\n\nis this a num: (a) = "<<isnum(a);
	std::cout << "\n\nis this a num: (b) ="<<isnum(b);
	int x,y;
	std::cout<<"\n lagnlhglag";
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
		y = stoi(b);
		
	}
	catch(...)
	{
		std::cout << "\n\nlines[3]**********"<<lines[3];
		std::cout << "value of lines[3]" << mapy[lines[3]]->getV();
		y = stoi(mapy[lines[3]]->getV());
	}
/*	if(isnum(b)){
		y = stoi(b);
	}else{
		y = stoi(mapy[lines[3]]->getV());
	}*/
	int j = x-y;
	std::cout<<"\n fuck this";
	mapy[lines[1]]->setVal(std::to_string(j));
	std::cout << "*************************************\n\n";
	std::cout << "\n" <<mapy[lines[1]]->getV() << "\n";
}

