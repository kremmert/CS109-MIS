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
#include <unistd.h>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;

//default constructor
Server::Server() {}

//static variables, used for thread method
std::vector<std::vector<std::string>> Server::linesthread;//parsed lines of code
map <string,Instructions *> Server::store;// map of variables made in the .mis ex VAR int...
std::map<std::string, int> Server::labelsstuff;//map of labels with line number
//std::map<int, int> Server::threadsbend;// map of mape[thread_begin_line#]= thread_end_line#
int Server::threadnum;//used to pass counter to thread
TCPServerSocket * Server::sock;//used for initial socket, and a get method to be used in thread class
	
Server::Server(std::string a)
{	
	input = a;
    this->readLines();
}

//constructor for new threads
Server::Server(int cthread, map <string,Instructions *> varsmap, bool flagend, std::vector<std::vector<std::string>> codelines,std::map <std::string,int> labelmap){
	this->counter = cthread;
	this->storevobj = varsmap;
	this->flagend = true;
	this->lines = codelines;
	this->labels = labelmap;
	this->morethanfetch();
}

//destructor
Server::~Server()
{

}

void Server::readLines()
{	//flagend is used to determine if this is the main program or a thread running the code
	flagend = false;
    Parse p;//parse obj
    //lines = p.parsingf(input);//parsed lines of code
	if(lines[0][0].compare("")==0) return;//if lines is empty, do nothing
	labels = p.labelget(lines);// get map of labels with line num
	threadsbend = p.threadends(lines);
	std::vector<std::string> outp(200);
    this->morethanfetch();//start executing code
}

void Server::morethanfetch()
{
	std::mutex m;
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
		}else if((lines[counter-1][0].compare("THREAD_END")==0)){//checks for thread_end
			if(flagend) {//if this is a thread, quit
				return;
			}
			else {
				continue;//otherwise continue on
			}
		}else if(lines[counter-1][0].compare("THREAD_BEGIN")==0){
			//creates a new thread, updates counter to thread_end
			threadnum = counter-1;
			linesthread = lines;
			store = storevobj;
			labelsstuff = labels;
			Thread * t2 = new Thread();
			t2->start(); //starts executing thread
			threads.push_back(t2); //places thread object into vector for easy barrier
			counter = threadsbend[counter-1]; //sets counter to thread_end
			counter -= 1;
		}else if(lines[counter-1][0].compare("BARRIER")==0) {
			barrier();//call barrier method. Used for threads.wait for thread to end
		}else if(lines[counter-1][0].compare("OUT")==0)
		{
			m.lock();
			Out p;
			std::vector<std::string> temp = p.outputV(lines[counter-1],this->storevobj);
			outp.reserve(outp.size() + temp.size());
			outp.insert(outp.end(),temp.begin(),temp.end());
			m.unlock();
		}else if(lines[counter-1][0].compare("LOCK")==0){
			//m.lock();
		}else if(lines[counter-1][0].compare("UNLOCK")==0){
			//m.unlock();
		}
		else{
			//call function : like add or sub
			vobj[lines[counter-1][0]]->functor(lines[counter-1],this->storevobj);
		}
		
	}

}

//blocks the main untill all threads are executed
void Server::barrier() {
 	for ( int i = 0 ; i < threads.size();i++){
 		threads[i]->waitForRunToFinish();
	}
}

//getters for various variables
int Server::getCounter()
{
	return threadnum;
}

std::vector<std::vector<std::string>> Server::getLines()
{
	return linesthread;//return the parsed lines of code.
}

std::map <std::string,Instructions *> Server::getObj()
{
	return store;//return the map of stored variables
}

std::map<std::string, int> Server::getLabel()
{
	return labelsstuff;//return map of stored labels;
}

TCPServerSocket * Server::getSock()
{
	return sock;//return main socket
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

//setter for lines
void Server::setLines(std::vector<std::vector<std::string>> lines)
{
	this->lines = lines;
}

//number of lines in file
int Server::howmanyargs(std::vector<std::string> args){
	int zz =0;
	while(1){
		if(args[zz].compare("")==0){
			return zz;
		}
		zz++;
	}
	return zz;
}
//this method get packets from client
//calls methods to execute code
//then Output.out file to client
void Server::sConnection(TCPSocket * client)
{
	int x = 0;
	int y = 0;
	int argnum = 0;
	char buffer[1024];
	std::vector<std::vector<std::string>> v(50,std::vector<string>(50));
	
	//get number of lines
	y = client->readFromSocketWithTimeout(buffer,32,20,10000);
	
	stringstream aaa(buffer);
	aaa >> y;// y = number of lines
	
	for(int h = 0 ;h < y ;h ++ )
	{			
		//get number of args
		y = client->readFromSocketWithTimeout(buffer,32,20,10000);
		if(y==0){//received zero packets
			break;
		}
		stringstream aaa(buffer);//convert buffer
		aaa >> argnum;//argnum = number of args
		for(int ff = 0; ff <argnum;ff++ ){
			x = client->readFromSocketWithTimeout(buffer,32,20,10000); //read from socket, give timeout of 20 sec and 10000miliseconds
			if(x == 0) //if buffer is empty break
				break;
			else {
				std::cout << buffer <<" "; //turn char* into stringstream
				stringstream s;//convert buffer
				s << buffer;
				v[h][ff] = s.str(); //places a string into vector
			}
		}
		std::cout<<std::endl;
	}
	this->setLines(v); //set lines then execute the instructions
	this->readLines();
	argnum = 0;

	//returning Output.out

	Parse p;//parse obj
    //std::vector<std::vector<std::string>> outp = p.parsingf("Output.out");
	int gg=0;	
	int yy=0;		
	//gets the number of filled lines in vector
	for(gg = 0; gg < outp.size(); gg++){
		if(outp[gg].compare("")==0){
			continue;
		}
		yy++;
		std::cout << "\noutp stuff"<< outp[gg];
	}

	//write to socket 
	client->writeToSocket(std::to_string(yy).c_str(),32);
	for(int x = 0; x < outp.size(); x++){//for x to #of lines in outp
		//argnum = this->howmanyargs(outp[x]); //gets number of args
		//client->writeToSocket(std::to_string(argnum).c_str(),32);
		//for(int starts = 0; starts< argnum; starts++){//for the number of strings in outp[x]
			//std::cout<<outp[x][starts].c_str();
		if(outp[x].compare("")!=0)
			client->writeToSocket(outp[x].c_str(),32); //sends data
		//}
	}
}

int main(int argc,char ** argv){
	
	if ( argc != 3) { // Check on the number of arguments and exit if incorrect
		printf ("usage: server	serverIPaddress	  serverport");
		exit(1);
	}
	
	vector <Thread *> t1; //thread vector for the sequential MIS
	Server * s2 = new Server(); 
	s2->sock = new TCPServerSocket(argv[1],stoi(argv[2]),32); //permanent socket
	bool status = s2->sock->initializeSocket();
	Thread * t2;
	for(;;)
	{
		TCPSocket * client = s2->sock->getConnection();
		if (client == NULL) break;
		t2 = new Thread(client); //create a new thread
		t2->start(); //execute thread and place object in vector for barrier
		t1.push_back(t2);
		if(!t2->isRunning())
			t2->waitForRunToFinish();
	}
	return 0;   
}



