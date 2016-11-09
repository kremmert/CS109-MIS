#include "Parse.h"
#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include <vector>
#include <sstream>
#include <map>

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
vector<vector<string>> Parse::parsingf(){
	//BIG [CHANGE] currently only handles up to 50 lines need to expand to handle more dynamically
	std::vector<std::vector<std::string>> lines(50,std::vector<string>(50));
	//[CHANGE] to variable passed
	std::ifstream file("InputTest.txt");
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
			//compares temp to empty string; if temp is empty, compare returns 0
			if(temp.compare("")==0) break;//go to next line
			//put parameter at current position in current inner vector
		/*	if(temp[temp.size()]!='\0')
			{
				std::cout <<"\n\nsubstring getting fixed";
				//temp = temp.substr(0,temp.size()-1);
				temp = temp.c_str();
			} */
			lines[x][y] = temp;
			y++;
		}
		//inner vector position is reset
		y = 0;
		//goes to next vector being held in the outer vector
		x++;

	} 
	//Printing the 2d vector
	for(int i=0; i<lines.size(); ++i){
		//stops if vector isn't populated
		if(lines[i][0].compare("")==0) break;
		std::cout<<"\n";//newline
		for(int v = 0; v < lines[i].size(); ++v){	
			//if no parameter stop printing
			if(lines[i][v].compare("")==0) break;
			//print parameter at current position
			std::cout <<"arg" <<v<<":"<< lines[i][v] << "\t";
		}
		
	}
	
	cout<<"\n end parse \n";
	//return 2D vector of instructions
	return lines;
	
	
}
std::map <std::string,int> Parse::labelget(){
	std::map <std::string,int> labelmap;
	
	for(int x = 0; x <lines.size();x++){
		if (lines[x][0].compare("")==0) continue;
		if(lines[x][0].compare("LABEL")){
			labelmap[lines[x][0]]= x;
		}
	}
	return labelmap;
}

