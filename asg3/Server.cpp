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
    this->readLines();
}

Server::~Server()
{

}

void Server::readLines()
{
    Parse p;
    lines = p.parsingf();
	labels = p.labelget();
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
		
		
		cout<<"\ncounter:: "<<counter-1<<"\n"<<lines[counter-1][0];
		
		if(lines[counter-1][0].compare("VAR")==0){
			
		cout<<"if";
		Instructions * kk = vobj[lines[counter-1][2]];
		
		cout<<"\nhere 5";
		kk = kk->clone(lines[counter-1]);
		cout<<"\nhere 88888";
		storevobj[lines[counter-1][1]] = kk;
		cout<<"\nhere 7";
		}
		else{
			
			cout<<"\n else";
			cout<<"\n else";
			vobj[lines[counter-1][0]]->functor(lines[counter-1],storevobj);
			cout<<"\n hhosnb";
			cout<<"\n hhosnb";
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


template<typename T, typename... insns>
T Server::execute(T res, insns... args)
{

}

int main(){
    Server * s = new Server();
    cout << "\nmade it" << endl;
}



