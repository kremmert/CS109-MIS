#ifndef CLIENT_H
#define CLIENT_H
#include "includes.h"
#include <vector>
class Client {
public:
    Client();//constructor
    virtual ~Client();//destructor
private:
	int howmanyargs(std::vector<std::string>);
};

#endif