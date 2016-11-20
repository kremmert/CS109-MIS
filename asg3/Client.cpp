#include "Client.h"
#include "TCPSocket.h"
#include "includes.h"
#include "Parse.h"
#include <vector>
Client::Client() {
}

Client::~Client() {
	
}

void terminate_with_error (int sock)
{
    //printf ("%s\n",error_msg); // printing error
    //perror("Socket Error:"); // printing system error
    printf("error\n");
    if (sock != -1) // Close socket and exit is socket opened
    {
    close (sock);
    exit(1);
    }
}

int Client::howmanyargs(std::vector<std::string> args){
	int zz =0;
	while(1){
		if(args[zz].compare("")==0){
			return zz;
		}
		zz++;
	}
	return zz;
}
	
int main()
{
	int argnum = 0;
	
	Client c;

	std::cout<<"here1"<<std::endl;
	Parse p;//parse obj
    std::vector<std::vector<std::string>> lines = p.parsingf("InputTest2.mis");//parsed lines of code
	//if(lines[0][0].compare("")==0) return 0;//if lines is empty, do nothing
	//std::map <std::string,int> mapy = p.labelget(lines);// get map of labels with line num
    //this->morethanfetch();//start executing code
	std::cout<<"here3"<<std::endl;
	int gg=0;
	for(gg = 0; gg < 50; gg++){
		if(lines[gg][0].compare("")==0){
			break;
		}
	}

     TCPSocket * test = new TCPSocket((char*)("128.114.104.57"),9999);
	std::cout<<"here7"<<std::endl;
	 
	 
	test->writeToSocket(std::to_string(gg).c_str(),512);
     //test->writeToSocket("Hello there\n",65536);
	 while(1){

		 
		for(int x = 0; x < gg; x++){
			argnum = c.howmanyargs(lines[x]);
			test->writeToSocket(std::to_string(argnum).c_str(),512);
			for(int starts = 0; starts< argnum; starts++){
				test->writeToSocket(lines[x][starts].c_str(),512);
				
			}
		
		}
	 }
	std::cout<<"here99"<<std::endl;
     return 0;   
}
