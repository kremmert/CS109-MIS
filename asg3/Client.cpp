#include "Client.h"
#include "TCPSocket.h"
#include "includes.h"
#include "Parse.h"
#include <vector>
#include <iostream>
#include <fstream>
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

	Parse p;//parse obj
    std::vector<std::vector<std::string>> lines = p.parsingf("InputTest3.mis");//parsed lines of code
	//if(lines[0][0].compare("")==0) return 0;//if lines is empty, do nothing
	//std::map <std::string,int> mapy = p.labelget(lines);// get map of labels with line num
    //this->morethanfetch();//start executing code
	int gg=0;
	for(gg = 0; gg < 50; gg++){
		if(lines[gg][0].compare("")==0){
			break;
		}
	}

     TCPSocket * test = new TCPSocket((char*)("128.114.104.56"),9999);


	 
	 
	test->writeToSocket(std::to_string(gg).c_str(),32);
     //test->writeToSocket("Hello there\n",65536);


		 
	for(int x = 0; x < gg; x++){
		argnum = c.howmanyargs(lines[x]);
		test->writeToSocket(std::to_string(argnum).c_str(),32);
		for(int starts = 0; starts< argnum; starts++){
			std::cout<<lines[x][starts].c_str();
			test->writeToSocket(lines[x][starts].c_str(),32);
			
		}
		std::cout<<std::endl;
	
	}

	std::ofstream outputFile;;
	outputFile.open("Output.out",std::ios::app);

	int x = 0;
	int y = 0;
	argnum = 0;
	char buffer[1024];
	int counter = 0;
	std::vector<std::vector<std::string>> v(50,std::vector<string>(50));
	
	//get number of lines
	y = test->readFromSocketWithTimeout(buffer,32,20,10000);
	
	stringstream aaa(buffer);
	aaa >> y;// y = number of lines
	
	for(int h = 0 ;h < y ;h ++ )
	{			
		//get number of args
		y = test->readFromSocketWithTimeout(buffer,32,20,10000);
		if(y==0){
			break;
		}
		stringstream aaa(buffer);
		aaa >> argnum;//argnum = number of args
		for(int ff = 0; ff <argnum;ff++ ){
			x = test->readFromSocketWithTimeout(buffer,32,20,10000);
			if(x == 0)
				break;
			else {
				std::cout << buffer <<" ";
				stringstream s;
				s << buffer;
				outputFile << s.str();
				
			}
		}
		std::cout<<std::endl;
		

	}
	//close file
	outputFile.close();

     return 0;   
}
