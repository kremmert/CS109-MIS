#include "Server.h"
#include "Instructions.h"
#include "Var.h"
#include "Parse.h"
#include "Numeric.h"
#include "Real.h"
#include "Char.h"
#include "String.h"
#include "Sub.h"
#include "Mul.h"
#include "Add.h"
#include "Div.h"
#include "Sleep.h"
#include "Assign.h"
#include "Out.h"
#include "Set_Str_Char.h"
#include "Get_Str_Char.h"
using namespace std;

Server::Server()
{	
}
Server::Server(std::string a)
{	
	input = a;
    this->readLines();
}

Server::~Server()
{

}

void Server::readLines()
{
    Parse p;
    lines = p.parsingf(input);
	if(lines[0][0].compare("")==0) return;
	labels = p.labelget(lines);
    this->morethanfetch();
}

void Server::morethanfetch()
{

	map <string,Instructions *> vobj;//var obj
	map <string,Instructions *> storevobj;//store var obj

	vobj["REAL"] = new Real();
	vobj["NUMERIC"] = new Numeric();
	vobj["STRING"] = new String();
	vobj["CHAR"] = new Char();
	

	vobj["ADD"] = new Add();
	vobj["SUB"] = new Sub();
	vobj["MUL"] = new Mul();
	vobj["DIV"] = new Div();
	vobj["SLEEP"] = new Sleep();
	vobj["ASSIGN"] = new Assign();
	vobj["OUT"] = new Out();
	vobj["SET_STR_CHAR"] = new Set_Str_Char();
	vobj["GET_STR_CHAR"] = new Get_Str_Char();
	
	
	cout<<lines.size();
	cout<<"\n"<<lines[0].size();
	while(counter<lines.size()){
		counter++;
		if(lines[counter-1][0].compare("")==0) continue;
		
		
		
		if(lines[counter-1][0].compare("VAR")==0){
			
		Instructions * kk = vobj[lines[counter-1][2]];
		
		kk = kk->clone(lines[counter-1]);
		
		storevobj[lines[counter-1][1]] = kk;
		}else if(lines[counter-1][0].compare("LABEL")==0){
			cout<<"\nchan chan: "<<counter;
			//labels were put into a map with line number right after being parsed
		}else if(lines[counter-1][0].substr(0,3).compare("JMP")==0){
			
			std::cout<<"\nchan chan: "<<labels[lines[counter-1][1]];
			jump(storevobj);
			std::cout<<"\n counter after jump"<<counter;
		}
		else{
			
			vobj[lines[counter-1][0]]->functor(lines[counter-1],storevobj);
			
		}
		
	}
	//fuck printing map
	for (std::map<string,Instructions*>::iterator it=storevobj.begin(); it!=storevobj.end(); ++it)
		std::cout <<"\n"<< it->first << " => " << it->second << '\n';

	cout<< "\n printing stored variables";


	for (std::map<string,int>::iterator it=labels.begin(); it!=labels.end(); ++it)
		std::cout <<"\n"<< it->first << " => " << it->second << '\n';
	
	
	cout<<"\n end?";
}

void Server::jump(std::map <std::string, Instructions *> storevobj){
	
	this->infinite++;
	if(infinite>1000){
		std::cout<<"\n infinite loop: ignoring jump";
		return;
	}
	std::string z = lines[counter-1][0];//type of jump
	std::string a = lines[counter-1][1];//where im jumping
	std::string b = lines[counter-1][2];//var or int
	std::string c = lines[counter-1][3];//var or int
	int x = 0;
	int y = 0;
	
	for (std::map<string,int>::iterator it=labels.begin(); it!=labels.end(); ++it)
		std::cout <<"\n"<< it->first << " => " << it->second << '\n';
	std::cout<<"\nline[0]: COUNTER"<<counter;
	std::cout<<"\nline[0]: *********"<<lines[counter-1][0];
	std::cout<<"\nline[0]: ??????????"<<lines[counter-1][1];
	std::cout<<"\nline[0]: VALLLLLUE"<<labels[lines[counter-1][1]];
	cout<<"\n z: "<<z<<"\n a: "<<a <<"\n b: "<< b <<"\n c"<< c;
	cout<<"\n counter: "<< counter;
	
	if(z.compare("JMP")==0)
	{
		counter = labels[a];
		cout<<"In JMP";
		return;
	}
	/*
	cout<<"a666: "<<labels[a];
	if(labels.find(a) == labels.end()){
		a = a.substr(0,a.size()-1);
		cout<<"\n found1";
		if(labels.find(a) == labels.end())
			cout<<"\n fou77777nd1";
	}
	*/
	

	if(storevobj.find(b) == storevobj.end()){
			b = b.substr(0,b.size()-1);
			if(storevobj.find(b)== storevobj.end()){


				x = std::stoi(lines[counter-1][2]);
			}else{
			x = std::stoi((storevobj[b])->getV());	
			}
	}else{
		x = std::stoi((storevobj[b])->getV());
		
	}

	
	if(z.compare("JMPZ")==0){
		if(x==0)
			counter = labels[lines[counter-1][1]];
		cout<<"\nIn JMPZ"<<counter;
		return;
	}
	
	if(z.compare("JMPNZ")==0){
		if(x!=0)
			counter = labels[lines[counter-1][1]];
		cout<<"In JMPNZ";
		return;
	}
	
	if(storevobj.find(c) == storevobj.end()){
			c = c.substr(0,c.size()-1);
			if(storevobj.find(c)== storevobj.end()){


				y = std::stoi(lines[counter-1][2]);
			}else{
			y = std::stoi((storevobj[c])->getV());	
			}
	}else{
		y = std::stoi((storevobj[c])->getV());
		
	}
	
	if(z.compare("JMPGT")==0){
		if(x>y)
			counter = labels[lines[counter-1][1]];
		cout<<"In JMPGT";
		return;
	}
	if(z.compare("JMPGTE")==0){
		if(x>=y)
			counter = labels[lines[counter-1][1]];
		cout<<"In JMPGTE";
		return;
	}
	if(z.compare("JMPLT")==0){
		if(x<y)
			counter = labels[lines[counter-1][1]];
		cout<<"\n x :" <<x;
		cout<<"\n y :" <<y;
		cout<<"\n In JMPLT"<<counter;
		return;
	}
	if(z.compare("JMPLTE")==0){
		//we can't do <= for some reason, IT DOESNT ***** WORK!
		if(x==y)
			counter = labels[lines[counter-1][1]];
		if(x<y)
			counter = labels[lines[counter-1][1]];
		cout<<"In JMPLTE"<<counter;
		cout<<"\n x :" <<x;
		cout<<"\n y :" <<y;
		return;
	}
}

int main(){
	
	std::string a;
	std::cout<<"please input file ending in .mis\n";
	std::cin>>a;
    Server * s = new Server(a);
    cout << "\nmade it" << endl;
}



