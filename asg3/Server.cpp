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
#include "includes.h"
#include "TCPSocket.h"
#include "TCPServerSocket.h"
#include "Thread.h"
using namespace std;

Server::Server()
{	
}
	std::vector<std::vector<std::string>> Server::lines;//parsed lines of code
	map <string,Instructions *> Server::storevobj;
	std::map<std::string, int> Server::labels;//map of labels with line number
	std::map<int, int> Server::threadsbend;
	int Server::threadnum;
	
Server::Server(std::string a)
{	
	input = a;
    this->readLines();
}

Server::Server(int cthread, map <string,Instructions *> varsmap, bool flagend, std::vector<std::vector<std::string>> codelines,std::map <std::string,int> labelmap){
	this->counter = cthread;
	this->storevobj = varsmap;
	this->flagend = true;
	this->lines = codelines;
	this->labels = labelmap;
	this->morethanfetch();
}

Server::~Server()
{

}

void Server::readLines()
{
	flagend = false;
    Parse p;//parse obj
    //lines = p.parsingf(input);//parsed lines of code
	if(lines[0][0].compare("")==0) return;//if lines is empty, do nothing
	labels = p.labelget(lines);// get map of labels with line num
	threadsbend = p.threadends(lines);
    this->morethanfetch();//start executing code
}

void Server::morethanfetch()
{

	map <string,Instructions *> vobj;//var obj, and functions
	//store var obj

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
			this->storevobj[lines[counter-1][1]] = kk;
			
		}else if(lines[counter-1][0].compare("LABEL")==0)
		{
			//labels were put into a map with line number right after being parsed
		}else if(lines[counter-1][0].substr(0,3).compare("JMP")==0){
			//execute jumps
			jump(this->storevobj);
		}else if((lines[counter-1][0].compare("THREAD_END")==0)&&flagend){//
			return;
		}else if(lines[counter-1][0].compare("THREAD_BEGIN")==0){
			//new thread(threadmethod);
			threadnum = counter-1;
			Thread * t2 = new Thread(&threadmethod);
			t2->start();
		}
		else{
			//call function : like add or sub
			vobj[lines[counter-1][0]]->functor(lines[counter-1],this->storevobj);
		}
		
	}

}

void * Server::threadmethod(void * ptr){
	int x = threadsbend[threadnum];
	Server * s5 = new Server(x,storevobj,true,lines,labels);
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
	int x = 0;
	int y = 0;
	

	//if the arg is jump
	if(z.compare("JMP")==0)
	{	//set counter to zero:THIS IS THE JUMP
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
void Server::setLines(std::vector<std::vector<std::string>> lines)
{
	this->lines = lines;
}

void Server::sConnection(TCPSocket * client)
{
	int x = 0;
	int y = 0;
	int argnum = 0;
	char buffer[1024];
	int counter = 0;
	std::vector<std::vector<std::string>> v(50,std::vector<string>(50));
	char test[1024];
	
	//get number of lines
	y = client->readFromSocketWithTimeout(buffer,256,20,10000);
	
	stringstream aaa(buffer);
	aaa >> y;// y = number of lines
	
	for(int h = 0 ;h < y ;h ++ )
	{			
		//get number of args
		y = client->readFromSocketWithTimeout(buffer,256,20,10000);
		if(y==0){
			break;
		}
		stringstream aaa(buffer);
		aaa >> argnum;//argnum = number of args
		for(int ff = 0; ff <argnum;ff++ ){
			x = client->readFromSocketWithTimeout(buffer,256,20,10000);
			if(x == 0)
				break;
			else {
				std::cout << buffer <<" ";
				stringstream s;
				s << buffer;
				v[h][ff] = s.str();

			}
		}
		std::cout<<std::endl;


	}
	this->setLines(v);
	this->readLines();
}

int main(){

        TCPServerSocket * s = new TCPServerSocket("128.114.104.57",9999,256);
        bool status = s->initializeSocket();
        TCPSocket * client = s->getConnection(0,0,256,256);
		Server * s2 = new Server();
		s2->sConnection(client);
        return 0;   
}



