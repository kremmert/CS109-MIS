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
	std::string blah;
	//vector<vector<string>> lines(50);
	int x = 0;
	int y = 0;

	while (std::getline(file, str))
	{
		std::stringstream ss(str);	// INstantiate stringstream with the current line just read
		
		while(ss.good()){
			if(y == 0){
			getline(ss,temp,'\t');
			lines[x][y] = temp;
			y++;
			}
			getline(ss, temp, ','); // Parse token until the first comma and store it in name
			if(temp.compare("")==0) break;
			lines[x][y] = temp;
			y++;
		}
		y = 0;
		x++;
		//std::cout<<"cout aray :    "<<this->lines[x-1][0]<<"\n";
		//printf("\n line %s \n", this->lines[x-1][0]);//doesnt work
		//std::cout<<"cout :"<<str<<"\n" ;//works
	} 
	for(int i=0; i<6; ++i){
		std::cout<<"\n";
		for(int v = 0; v < 6; ++v)
		{	if(lines[i][v].compare("")!=0) std::cout <<"arg" <<v<<":"<< lines[i][v] << "\t";
		}
		
	}
	

	return lines;
	
	
}

int main(int argc, char** argv)
{
	/*
	string program [100][100];
	string line = "";
	std::ifstream infile("InputTest.txt");
	while(std::getline(inFile,line)) 
	{ // Loop through the file lines
		printf(" line %s \n" , line);
	}
	inFile.close(); // Close file
	*/
	cout<<"\n";
	Parse *pthing = new Parse();
	pthing->parsingf();
}