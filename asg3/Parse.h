#ifndef PARSE_H
#define PARSE_H

#include<string>
#include <vector>
#include <map>

class Parse {
public:
	//constructor
    Parse();
	//copy constructor
    Parse(const Parse& orig);
	//destructor
    virtual ~Parse();
	//function to parse each line into the 2D vector and separate the type and 
	//parameters into different positions within the inner vector
	std::vector<std::vector<std::string>> parsingf(std::string input);
	
	std::map <std::string, int> labelget(std::vector<std::vector<std::string>> lines);

	
	
private:
	/*Holds the instructions of the functions in a 2D vector(vector of vectors)
	inner vector styled as follows:
	instruction name always in position 1 of inner vector 
	variables and literals in following positions as needed*/
	std::vector<std::vector<std::string>> lines;

};

#endif