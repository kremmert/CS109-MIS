#ifndef SERVER_H
#define SERVER_H

#include "common.h"
#include <map>
#include "Instructions.h"
#include "TCPServerSocket.h"
#include "TCPSocket.h"
class Server 
{
    private:
        static std::vector<std::vector<std::string>> lines;//parsed lines of code
		static map <string,Instructions *> storevobj;
		static std::map<std::string, int> labels;//map of labels with line number
		static std::map<int, int> threadsbend;
		static int threadnum;
		bool flagend;
		std::string input;//input file
        int counter = 0;//pointing to which line of code
    public:
		Server();
		Server(int cthread, map <string,Instructions *> varsmap, bool flagend, std::vector<std::vector<std::string>> codelines,std::map <std::string,int> labelmap);
        Server(std::string a); //map1 has everything instantiated, arrays allocated
        static TCPServerSocket * sock;
        void readLines();// calls method to parse
        void morethanfetch(); //count indexes until next insn
		void jump(std::map <std::string,Instructions *> storevobj);//jump function
		int infinite = 0;
        void setLines(std::vector<std::vector<std::string>> lines);
        void sConnection(TCPSocket * client);
		static void * threadmethod(void *);
        int getCounter();
        std::vector<std::vector<std::string>> getLines();
        std::map <std::string,Instructions *> getObj();
        std::map<std::string, int> getLabel();
        TCPServerSocket * getSock();
        //forms and puts object into map, clone 
        //then performs the insns, and stores into another map, then calls fetch again
        //increments counter
        virtual ~Server();

};

#endif