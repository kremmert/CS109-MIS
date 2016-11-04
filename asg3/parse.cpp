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
			getline(ss, temp, ','); // Parse token until the first comma and store it in name
			lines[x][y] = temp;
			y++;
		}
		y = 0;
		x++;
		//std::cout<<"cout aray :    "<<this->lines[x-1][0]<<"\n";
		//printf("\n line %s \n", this->lines[x-1][0]);//doesnt work
		//std::cout<<"cout :"<<str<<"\n" ;//works
	} 
	for(int i=0; i<lines.size(); ++i){
		std::cout << lines[i][0] << "\n";
		
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
	
	Parse *pthing = new Parse();
	pthing->parsingf();
}