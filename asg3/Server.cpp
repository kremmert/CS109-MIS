#include "Server.h"
#include "parse.cpp"
using namespace std;

Server::Server()
{
    this->readLines();
}

Server::~Server()
{

}

void Server::readLines()
{
    Parse p;
    lines = p.parsingf();
    this->fetch();
}

void Server::fetch()
{
    string str = lines[counter][0];
    cout << "this is a test!!!!!!!!!!!" << str << endl;
    counter++;
}

template<typename T, typename... insns>
T Server::execute(T res, insns... args)
{

}

int main(int argc, char** argv){
    Server * s = new Server();
    cout << "\nmade it" << endl;
}



