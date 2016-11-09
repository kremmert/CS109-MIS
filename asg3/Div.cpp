#include "Div.h"
#include "common.h"

Div::Div() {
}

Div::Div(const Div& orig) {
}

Div::~Div() {
}


//Divide the second parameter by the third parameter and store the result in the first parameter.	 
//Note: divide	by	zero	should	be	detected and reported.	

void Div:: divide(int c, int a, int b){
    if(b == 0){
        std::cout<<"divide by zero error";
        return;
    }


}

void Div::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
    std::string a = lines[2];
	std::string b = lines[3];
	int x,y;
	
	try{
		x = stoi(a);
	}
	catch(...)
	{
		x = stoi(mapy[lines[2]]->getV());
	}


	try{
		
		y = stoi(b);
		
	}
	catch(...)
	{
		std::string mn = lines[3].substr(0,lines[3].size()-1);
		y = std::stoi((mapy[mn])->getV());
	}
	if(y==0){
		std::cout<<" Divide by zero";
		return;
	}
	int j = x/y;
	mapy[lines[1]]->setVal(std::to_string(j));
	std::cout<<"\n result: "<<mapy[lines[1]]->getV();
	std::cout<<"\n";
}

