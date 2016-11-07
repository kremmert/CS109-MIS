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
	

	vobj["ADD"] = &Add::add;
	vobj["SUB"] = &Sub::subtract;
	vobj["MUL"] = &Mul::mul;
	vobj["DIV"] = &Div::divide;

	cout<<lines.size();
	cout<<"\n"<<lines[0].size();
	while(counter<lines.size()){
		counter++;
		if(lines[counter-1][0].compare("")==0) continue;
		
		
		cout<<"\ncounter:: "<<counter-1<<"\n";
		
		if(lines[counter][0].compare("VAR")==0){
			
		
		Instructions * kk = vobj[lines[counter-1][2]];
		
		cout<<"\nhere 5";
		kk = kk->clone(lines[counter-1]);
		cout<<"\nhere 88888";
		storevobj[lines[counter-1][1]] = kk;
		cout<<"\nhere 7";
		}
		else{
			storevobj[lines[counter-1][0]](lines[counter-1]);
		}
		
		//if(counter == lines.size()-1) break;
	}
	//fuck printing map
	for (std::map<string,Instructions*>::iterator it=storevobj.begin(); it!=storevobj.end(); ++it)
		std::cout <<"\n"<< it->first << " => " << it->second << '\n';

	cout<< "\n printing stored variables";
/* 	typedef map<string, Var * >::const_iterator MapIterator;
	for (MapIterator iter = storevobj.begin(); iter != storevobj.end(); iter++)
	{
		cout << "\n Key: " << iter->first << endl << "Values:";
		//fuck printing values
		typedef Var*::const_iterator ListIterator;
		for (ListIterator list_iter = iter->second.begin(); list_iter != iter->second.end(); list_iter++)
			cout << " " << *list_iter << endl;
	} */

	
	
	cout<<"\n end?";
	/*
    Var v;
    Var * w = v.decode(lines[counter]);
    string str;
    cout << endl;
    for(int i = 0; i < lines[counter].size(); ++i)
    {
        str = lines[counter][i];
        cout << str << endl;
        if(lines[counter][i].compare("")==0) break;
    }
    counter++;
	*/
}

template<typename T, typename... insns>
T Server::execute(T res, insns... args)
{

}

int main(){
    Server * s = new Server();
    cout << "\nmade it" << endl;
}



