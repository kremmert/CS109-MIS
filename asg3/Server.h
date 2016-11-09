#ifndef SERVER_H
#define SERVER_H

#include "common.h"
#include <map>
#include "Instructions.h"
class Server 
{
    private:
        std::vector<std::vector<std::string>> lines;//parsed lines of code
		std::string input;//input file
        int counter = 0;//pointing to which line of code
        std::map<std::string, int> labels;//map of labels with line number
    public:
		Server();
        Server(std::string a); //map1 has everything instantiated, arrays allocated
        void readLines();// calls method to parse
        void morethanfetch(); //count indexes until next insn
		void jump(std::map <std::string,Instructions *> storevobj);//jump function
		int infinite = 0;
        //forms and puts object into map, clone 
        //then performs the insns, and stores into another map, then calls fetch again
        //increments counter
        virtual ~Server();

};

#endif