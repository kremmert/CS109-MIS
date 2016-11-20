#ifndef CLIENT_H
#define CLIENT_H
#include "includes.h"
#include <vector>
class Client {
public:
    Client();//constructor
    virtual ~Client();//destructor
	int howmanyargs(std::vector<std::string>);
private:
	
};

#endif