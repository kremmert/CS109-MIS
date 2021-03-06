#include "Parse.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <map>
#include <string.h> 

using namespace std;
//Constructor
Parse::Parse() {
//[CHANGE]accept filename and call parsingf()
}

//Copy Constructor
Parse::Parse(const Parse& orig) {
}

//Destructor
Parse::~Parse() {
//[CHANGE]probably need to destruct the 2D Vector
}

//[CHANGE] change to accept filename so it can call from constructor?
vector<vector<string>> Parse::parsingf(std::string input){
	//BIG [CHANGE] currently only handles up to 50 lines need to expand to handle more dynamically
	std::vector<std::vector<std::string>> lines(50,std::vector<string>(50));
	//[CHANGE] to variable passed
	if(input.find(".mis")==-1 && input.find(".out")==-1){
		std::cout<<"\n not a .mis file";
		return lines;
	}
	std::ifstream file(input);
	//string variable to hold current line being parsed
	std::string str;
	//used to hold what was parsed
	std::string temp;

	//track position within vector
	int x = 0;//used for line#
	int y = 0;//used for arg #
	
	//loop until eof
	while (std::getline(file, str))
	{
		std::stringstream ss(str);	
		if(x!=0){//if statement to remove null char at end of line.
			if(input.find(".out")==-1)// if this is not .out
				lines[x-1][y-1] = lines[x-1][y-1].substr(0,lines[x-1][y-1].size()-1);
		}
		y = 0;
		//check for eof in stream (end of the line in this case)
		while(ss.good()){
			if(y == 0){//get instruction name
				if(ss.str().find(" ")<ss.str().find("\t")){
					//handles name & params separated by space
					getline(ss,temp,' ');
				}else{
					//handles name & params separated by tab
					getline(ss,temp,'\t');
				}
				//set name at current position in current inner vector
				lines[x][y] = temp;
				//increment inner position
				
				y++;
				continue;
			}
			//get params(all separated by commas)
			getline(ss, temp, ',');
			//set vector lines [lines number][arg number ] = arg/paramter
			lines[x][y] = temp;
			y++;
		}
		x++;
		
	} 

	
	//return 2D vector of instructions
	return lines;
	
	
}
// return map of labels with line number
std::map <std::string,int> Parse::labelget(std::vector<std::vector<std::string>> lines){
	std::map <std::string,int> labelmap;
	
	for(int x = 0; x <lines.size();x++){
		//if empty line continue
		if (lines[x][0].compare("")==0) continue;
		if(lines[x][0].compare("LABEL")==0){
			labelmap[lines[x][1]]= x;
			//set map[label] = line number
		}
	}
	return labelmap;
}
//make a map of where the threads begin end are
std::map <int,int> Parse::threadends(std::vector<std::vector<std::string>> lines){
	std::map <int,int> threadendmap;
	//map format = map[thread_begin_line#] = thread_end_line#
	int key = 0;
	
	for(int x = 0; x <lines.size();x++){
		//if empty line continue
		if (lines[x][0].compare("")==0) continue;
		if(lines[x][0].compare("THREAD_BEGIN")==0){
			key = x;
			//set key = thread begin line #
		}
		if(lines[x][0].compare("THREAD_END")==0){
			threadendmap[key]= x;
			//set map[thread_begin_line#] = thread_end_line#
		}
	}
	return threadendmap;
}
