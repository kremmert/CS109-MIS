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
	if(input.find(".mis")==-1){
		std::cout<<"\n not a .mis file";
		return lines;
	}
	std::ifstream file(input);
	//string variable to hold current line being parsed
	std::string str;
	//
	std::string temp;

	//track position within vector
	int x = 0;
	int y = 0;
	
	//loop until eof
	while (std::getline(file, str))
	{
		//use string as a sequence of chars
		std::stringstream ss(str);	
		if(x!=0){
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
			}
			//get params(all separated by commas)
			getline(ss, temp, ',');

			lines[x][y] = temp;
			//std::cout<<" \t"<<lines[x][y];
			y++;
		}//get rid of null char at the end
		std::cout<<"\n";
		
		std::cout<<"\t"<<lines[x][0]<<"\t"<<lines[x][1]<<"\t"<<lines[x][2]<<"\t"<<lines[x][3];
		//inner vector position is reset
		
		//goes to next vector being held in the outer vector
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

