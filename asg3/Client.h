#ifndef CLIENT_H
#define CLIENT_H
#include "includes.h"
#include <vector>
class Client {
public:
    Client();//constructor
    virtual ~Client();//destructor
	int howmanyargs(std::vector<std::string>);// finds out how many non empty string there are
	//used to find out how many args per line of code
private:
	
};

#endif