#include "Parse.h"
#include<iostream>
#include<fstream>
#include<string>
#include <stdio.h>

using namespace std;
Parse::Parse() {
}

Parse::Parse(const Parse& orig) {
}

Parse::~Parse() {
}

void Parse::parsingf(){
	
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
	std::ifstream file("InputTest.txt");
	std::string str;
	std::string liny;
	std::string file_contents;
	while (std::getline(file, str))
	{
		liny = str;
	printf(" line %s \n", liny);//doesnt work
	std::cout<<"cout :"<<str<<"\n" ;//works
	}  
}