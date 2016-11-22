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
	TCPSocket * test;//socket to send/receive things
	void receivefile();//receive file from server
	void sendfile(std::string input);//send parsed file in vector form to server
private:
	
};

#endif