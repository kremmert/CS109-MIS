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
	// make map of labels, map[label]= line number, method is passed parsed lines of code
	std::map <std::string, int> labelget(std::vector<std::vector<std::string>> lines);
	//make map of threads, map[thread_begin_line#] = thread_end_line#
	std::map <int, int> threadends(std::vector<std::vector<std::string>> lines);

	
	
private:
	//Holds the instructions of the .mis file
	//sperated by lines[line#][parameter#] = string
	std::vector<std::vector<std::string>> lines;

};

#endif