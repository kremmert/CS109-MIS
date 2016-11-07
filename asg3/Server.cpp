#include "Server.h"
#include "var.h"
#include "parse.h"
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
    Var v;
    Var * w = v.decode(lines[counter]);
    string str;
    cout << endl;
    for(int i = 0; i < lines[counter].size(); ++i)
    {
        str = lines[counter][i];
        cout << str << endl;
        if(lines[counter][i].compare("")==0) break;
    }
    counter++;
}

template<typename T, typename... insns>
T Server::execute(T res, insns... args)
{

}

int main(){
    Server * s = new Server();
    cout << "\nmade it" << endl;
}



