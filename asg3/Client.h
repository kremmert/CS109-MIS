#ifndef CLIENT_H
#define CLIENT_H
#include "includes.h"
#include <vector>
#include "TCPSocket.h"
class Client {
public:
    Client(char * a,char * b);//constructor
    virtual ~Client();//destructor
	int howmanyargs(std::vector<std::string>);// finds out how many non empty string there are
	//used to find out how many args per line of code
	TCPSocket * test;
	void receivefile();
	void sendfile(std::string input);
private:
	
};

#endif