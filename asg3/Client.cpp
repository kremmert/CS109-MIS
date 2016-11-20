#include "Client.h"
#include "TCPSocket.h"
#include "includes.h"
#include "Parse.h"

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


	
int main()
{
	
	std::ifstream file("InputTest2.mis");
	auto input = file;
	
	Parse p;//parse obj
    std::vector<std::vector<std::string>> lines = p.parsingf(input);//parsed lines of code
	if(lines[0][0].compare("")==0) return;//if lines is empty, do nothing
	//std::map <std::string,int> mapy = p.labelget(lines);// get map of labels with line num
    //this->morethanfetch();//start executing code
	int gg=0;
	for(gg = 0; gg < 50; gg++){
		if(lines[gg][0].compare("")==0){
			return gg;
		}
	}

     TCPSocket * test = new TCPSocket((char*)("128.114.104.57"),9999);
	 
	 
	test->writeToSocket((char*)(gg),512);
     //test->writeToSocket("Hello there\n",65536);
	 for(int x = 0; x < gg; x++){
		test->writeToSocket(lines[x][0].c_str(),512);
		
	 }
     return 0;   
}
