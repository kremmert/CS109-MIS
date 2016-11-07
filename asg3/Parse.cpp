#include "Parse.h"
#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;
Parse::Parse() {
	
}

Parse::Parse(const Parse& orig) {
}

Parse::~Parse() {
}

vector<vector<string>> Parse::parsingf(){
	std::vector<std::vector<std::string>> lines(50,std::vector<string>(50));
	std::ifstream file("InputTest.txt");
	std::string str;
	std::string temp;


	int x = 0;
	int y = 0;

	while (std::getline(file, str))
	{
		std::stringstream ss(str);	
		
		while(ss.good()){
			
			if(y == 0){
				if(ss.str().find(" ")<ss.str().find("\t")){
					getline(ss,temp,' ');
					lines[x][y] = temp;
					y++;
				}else{
					getline(ss,temp,'\t');
					lines[x][y] = temp;
					y++;
				}
				
			}
			getline(ss, temp, ',');
			if(temp.compare("")==0) break;
			lines[x][y] = temp;
			y++;
		}
		y = 0;
		x++;

	} 
	for(int i=0; i<lines.size(); ++i){
		if(lines[i][0].compare("")==0) break;
		std::cout<<"\n";
		for(int v = 0; v < lines[i].size(); ++v)
		{	if(lines[i][v].compare("")==0) break;
			std::cout <<"arg" <<v<<":"<< lines[i][v] << "\t";
		}
		
	}
	
	cout<<"\n end parse \n";
	return lines;
	
	
}

