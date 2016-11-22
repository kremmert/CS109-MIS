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
//this method finds out how many non empty string there are. this is used for finding how many parameters there are
int Client::howmanyargs(std::vector<std::string> args){
	int zz =0;
	while(1){
		if(args[zz].compare("")==0){//stop as soon as it encounters an empty string
			return zz;// return how many non-emtpy strings it found
		}
		zz++;
	}
	return zz;//in case something goes wrong
}
	
int main()
{
	int argnum = 0;
	
	Client c;

	Parse p;//parse obj
    std::vector<std::vector<std::string>> lines = p.parsingf("InputTest3.mis");//parsed lines of code
	
	int gg=0;//gg = how many lines of code there are
	for(gg = 0; gg < 50; gg++){
		if(lines[gg][0].compare("")==0){//break as soon as there is an empty string
			break;
		}
	}
	
	//tcp socket 
    TCPSocket * test = new TCPSocket((char*)("128.114.104.56"),9999);


	 
	//send number of lines of code. THis will be used so that it can expect how many sends
	test->writeToSocket(std::to_string(gg).c_str(),32);


	//for loop for # of lines of code
	for(int x = 0; x < gg; x++){
		//find # of args per line of code
		argnum = c.howmanyargs(lines[x]);
		//send # of paramenters so server know what to expect
		test->writeToSocket(std::to_string(argnum).c_str(),32);
		for(int starts = 0; starts< argnum; starts++){
			std::cout<<lines[x][starts].c_str();
			//send code
			test->writeToSocket(lines[x][starts].c_str(),32);
			
		}
		std::cout<<std::endl;
	
	}
	//this is for receiving file
	std::ofstream outputFile;;
	outputFile.open("Output.out",std::ios::app);
	
	int x = 0;
	int y = 0;
	argnum = 0;
	//buffer for packets received
	char buffer[1024];
	std::vector<std::vector<std::string>> v(50,std::vector<string>(50));
	
	//get number of lines
	y = test->readFromSocketWithTimeout(buffer,32,120,10000);
	
	stringstream aaa(buffer);//convert buffer to stringstream
	aaa >> y;// y = number of lines, converted to in
	//y = # of lines expected
	for(int h = 0 ;h < y ;h ++ )
	{			
		//get number of args
		y = test->readFromSocketWithTimeout(buffer,32,20,10000);
		if(y==0){
			break;
		}
		stringstream aaa(buffer);//convert to stringstream to int
		aaa >> argnum;//argnum = number of args expected
		for(int ff = 0; ff <argnum;ff++ ){
			//receive string
			x = test->readFromSocketWithTimeout(buffer,32,20,10000);
			if(x == 0)
				break;
			else {
				stringstream s;
				s << buffer;//convert buffer to string stream
				std::cout<<s.str()<<" ";
				//write to Output.out
				outputFile << s.str();
				
			}
		}
		//new line for Output.out for every new line expected
		outputFile<<std::endl;
		std::cout<<std::endl;
		

	}
	//close file
	outputFile.close();

     return 0;   
}
