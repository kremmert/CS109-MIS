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
	std::cout<<"\n help me";
	std::string a = lines[2];
	std::string b = lines[3];
	int x,y;

	if(isnum(a)){
		x = stoi(a);
	}else{
		x = stoi(mapy[lines[2]]->getV());
	}
	
	if(isnum(b)){
		y = stoi(b);
	}else{
		y = stoi(mapy[lines[3]]->getV());
	}
	int j = x-y;
	mapy[lines[1]]->setVal(std::to_string(j));
	std::cout << "*************************************\n\n";
	std::cout << "\n" <<mapy[lines[1]]->getV() << "\n";
}

