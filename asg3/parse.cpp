#include "Parse.h"
#include<iostream>
#include<fstream>
#include<string>
Parse::Parse() {
}

Parse::Parse(const Parse& orig) {
}

Parse::~Parse() {
}

Parse::parsingf(){
	
}

int main(int argc, char** argv)
{
	ifstream readFile("InputTest.txt");
	
	while(getline(readFile,line)) 
	{ // Loop through the file lines
		stringstream iss(line); // INstantiate stringstream with the current line just read
		printf(" line " + %s + "\n" , line)
	}
	readFile.close(); // Close file
}