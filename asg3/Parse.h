#include<string>
#include <vector>

class Parse {
public:
    Parse();
    Parse(const Parse& orig);
    virtual ~Parse();
	std::vector<std::vector<std::string>> parsingf();

	
	
private:
	std::vector<std::vector<std::string>> lines;

};