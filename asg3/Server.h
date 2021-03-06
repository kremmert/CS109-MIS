#ifndef SERVER_H
#define SERVER_H

#include "common.h"
#include <map>
#include "Instructions.h"
#include "TCPServerSocket.h"
#include "TCPSocket.h"
#include "Thread.h"
class Server 
{
    private:
        std::vector<std::vector<std::string>> lines;//parsed lines of code
        static std::vector<std::vector<std::string>> linesthread;
		map <string,Instructions *> storevobj;//map of variables made in the .mis
        static map <string,Instructions *> store;
		std::map<std::string, int> labels;//map of labels with line number
        static std::map<std::string, int> labelsstuff;
		/*static*/ std::map<int, int> threadsbend;//map[threadbegin_line#]=threadend_line#
		static int threadnum;
		bool flagend;//used to see if in a threadbeing-end
		std::string input;//input file
        int counter = 0;//pointing to which line of code
        vector <Thread *> threads;//thread manager vector
        std::vector<std::string> outp; //output
    public:
		Server();
		Server(int cthread, map <string,Instructions *> varsmap, bool flagend, std::vector<std::vector<std::string>> codelines,std::map <std::string,int> labelmap);
        Server(std::string a); //map1 has everything instantiated, arrays allocated
        static TCPServerSocket * sock;
        void readLines();// calls method to parse
        void morethanfetch(); //count indexes until next insn
		void jump(std::map <std::string,Instructions *> storevobj);//jump function
		int infinite = 0;//used for inifinite loop
        void setLines(std::vector<std::vector<std::string>> lines); //setter
        void sConnection(TCPSocket * client); //recieves and sends a file
        int getCounter();//getter
        void barrier(); //blocks till threads finish
        std::vector<std::vector<std::string>> getLines(); //getters
        std::map <std::string,Instructions *> getObj();
        std::map<std::string, int> getLabel();
        TCPServerSocket * getSock();
        int howmanyargs(std::vector<std::string> args); //get lines in a file
        //forms and puts object into map, clone 
        //then performs the insns, and stores into another map, then calls fetch again
        //increments counter
        virtual ~Server();

};

#endif