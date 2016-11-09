#ifndef SERVER_H
#define SERVER_H

#include "common.h"
#include <map>
#include "Instructions.h"
class Server 
{
    private:
        std::vector<std::vector<std::string>> lines;
		std::string input;
        int counter = 0;
        std::map<std::string, int> labels;
    public:
		Server();
        Server(std::string a); //map1 has everything instantiated, arrays allocated
        void readLines();
        void morethanfetch(); //count indexes until next insn
		void jump(std::map <std::string,Instructions *> storevobj);
		int infinite = 0;
        //forms and puts object into map, clone 
        //then performs the insns, and stores into another map, then calls fetch again
        //increments counter
        virtual ~Server();

};

#endif