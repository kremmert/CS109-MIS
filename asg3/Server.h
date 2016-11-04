#include "common.h"
#include <map>
class Server 
{
    private:
        std::vector<std::vector<std::string>> lines;
        int counter = 0;
        int * labels;
        std::map<std::string, Server *> map1;
        std::map<std::string, double> map2;
        std::map<std::string, std::string> map3;
    public:
        Server(); //map1 has everything instantiated, arrays allocated
        void readLines();
        void fetch(); //count indexes until next insn
        template<typename T, typename... insns>
        T execute(T res, insns... args);
        //forms and puts object into map, clone 
        //then performs the insns, and stores into another map, then calls fetch again
        //increments counter
        virtual ~Server();

};