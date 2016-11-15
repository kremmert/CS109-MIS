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
    Parse p;//parse obj
    lines = p.parsingf(input);//parsed lines of code
	if(lines[0][0].compare("")==0) return;//if lines is empty, do nothing
	labels = p.labelget(lines);// get map of labels with line num
    this->morethanfetch();//start executing code
}

void Server::morethanfetch()
{

	map <string,Instructions *> vobj;//var obj, and functions
	map <string,Instructions *> storevobj;//store var obj

	//var objects in map
	vobj["REAL"] = new Real();
	vobj["NUMERIC"] = new Numeric();
	vobj["STRING"] = new String();
	vobj["CHAR"] = new Char();
	
	//function objects in map
	vobj["ADD"] = new Add();
	vobj["SUB"] = new Sub();
	vobj["MUL"] = new Mul();
	vobj["DIV"] = new Div();
	vobj["SLEEP"] = new Sleep();
	vobj["ASSIGN"] = new Assign();
	vobj["OUT"] = new Out();
	vobj["SET_STR_CHAR"] = new Set_Str_Char();
	vobj["GET_STR_CHAR"] = new Get_Str_Char();
	
	
	//going through each linea of code 
	while(counter<lines.size()){
		counter++;
		//if line is empty go on to next line
		if(lines[counter-1][0].compare("")==0) continue;
		
		
		//if first arg is Var make variable
		if(lines[counter-1][0].compare("VAR")==0)
		{	//get type of var
			Instructions * kk = vobj[lines[counter-1][2]];
			//make var obj
			kk = kk->clone(lines[counter-1]);
			//store var
			storevobj[lines[counter-1][1]] = kk;
			
		}else if(lines[counter-1][0].compare("LABEL")==0)
		{
			//labels were put into a map with line number right after being parsed
		}else if(lines[counter-1][0].substr(0,3).compare("JMP")==0){
			//execute jumps
			jump(storevobj);
		}
		else{
			//call function : like add or sub
			vobj[lines[counter-1][0]]->functor(lines[counter-1],storevobj);
		}
		
	}

}
//executes jumps
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
	std::cout<<"\n a: "<<a;
	std::cout<<"\n b: "<<b;
	std::cout<<"\n c: "<<c;
	std::cout<<"\n z: "<<z;
	std::cout<<"\n end";
	int x = 0;
	int y = 0;
	

	//if the arg is jump
	if(z.compare("JMP")==0)
	{	//set counter to zero:THIS IS THE JUMP
		std::cout<<"\n labels:"<<labels[a];
		counter = labels[a];
		return;
	}

	
	//find var in map
	if(storevobj.find(b) == storevobj.end()){
		x = std::stoi(lines[counter-1][2]);

	}else{
		//its in map
		x = std::stoi((storevobj[b])->getV());
		
	}

	//arg is jump z, jump if is 0
	if(z.compare("JMPZ")==0){
		if(x==0)//compare
			counter = labels[lines[counter-1][1]];//jump
		return;
	}
	
	if(z.compare("JMPNZ")==0){
		if(x!=0)//compare
			counter = labels[lines[counter-1][1]];//jump
		return;
	}
	//see if its in map
	if(storevobj.find(c) == storevobj.end()){
		y = std::stoi(lines[counter-1][2]);

	}else{//its in map
		y = std::stoi((storevobj[c])->getV());
		
	}
	
	if(z.compare("JMPGT")==0){
		std::cout<<"\nx: "<<x;
		std::cout<<"\ny: "<<y;
		if(x>y)//compare
			counter = labels[lines[counter-1][1]];//jump
		return;
	}
	if(z.compare("JMPGTE")==0){
		if(x>=y)//compare
			counter = labels[lines[counter-1][1]];//jump
		return;
	}
	if(z.compare("JMPLT")==0){
		std::cout<<"\nx: "<<x;
		std::cout<<"\ny: "<<y;
		if(x<y)//compare
			counter = labels[lines[counter-1][1]];//jump
		return;
	}
	if(z.compare("JMPLTE")==0){
		//we can't do <= for some reason, IT DOESNT ***** WORK!
		if(x==y)//compare
			counter = labels[lines[counter-1][1]];//jump
		if(x<y)//compare
			counter = labels[lines[counter-1][1]];//jump
		return;
	}
}

int main(){
	
	std::string a;//will be nane of input file
	std::cout<<"please input file ending in .mis\n";
	std::cin>>a;
    Server * s = new Server(a);//start everything
	cout << "\nOut instructions are in file Output.out" << endl;
    cout << "Ending Program" << endl;
}



