#include "Server.h"
#include "var.h"
#include "parse.h"
#include "Numeric.h"
#include "Real.h"
#include "Char.h"
#include "String.h"
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
	cout<<"here1";
	map <string,Var *> vobj;//var obj
	map <string,Var *> storevobj;//store var obj
	cout<<"Here2\n";
	vobj["REAL"] = new Real();
	vobj["NUMERIC"] = new Numeric();
	vobj["STRING"] = new String();
	vobj["CHAR"] = new Char();
	cout<<"3\n";
	cout<<lines.size();
	cout<<"\n"<<lines[0].size();
	while(counter<lines.size()){
		counter++;
		if(lines[counter-1][0].compare("")==0) continue;
		cout<<"\ncounter:: "<<counter-1<<"\n";
		Var * kk = vobj[lines[counter-1][2]];
		cout<<lines[counter-1][2];
		kk = kk->clone(lines[counter-1]);
		storevobj[lines[counter-1][1]] = kk;

		
		//if(counter == lines.size()-1) break;
	}
	
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



