#include "common.h"
#include "Add.h"
using namespace std;
Add::Add()
{

}

Add::Add(const Add& orig)
{

}


Add::~Add()
{

}

template<typename T>
T add(T a)
{
    return a;
}

template<typename T, typename... num>
T add(T res, num... args)
{
    return res + add(args...);
}

void Add::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	std::cout<<"\n help me";
	std::string a = lines[2];

	int x = 0;
	int y = 0;
	int v = 2;
	while(v < lines.size())	{

		try{ 
			x = stoi(lines[v]);
		}
		catch(...) {
			x = stoi(mapy[lines[v]]->getV());
		}

		y+=x;
		if(lines[v+2].compare("")==0)
		{
			break;
		}

		v++;
	}
	x = 0;

	try{
		
		x = stoi(lines[v+1]);
		
	}
	catch(...)
	{
		for (std::map<std::string,Instructions*>::iterator it=mapy.begin(); it!=mapy.end(); ++it)
			std::cout <<"\n  Here: "<< it->first << " => " << it->second->getV() << "\n here3333";
		//std::string mn = lines[v+1].substr(0,lines[v+1].size()-1);
		//std::cout<<"\n\nsubstring asldfad " << mn;
		//x = std::stoi((mapy[lines[v+1]])->getV());


		//std::string mn = mapy[lines[v+1]]->getV();
		
		std::string mn = lines[v+1];
		/*
		if(mn.find('\0')!=-1){
			std::cout<<"\n here plase";
			mn = mn.substr(0,mn.find('\0')-1);
		}
		if(mn.find('\0')==-1){
			std::cout<<"\n here plase 55555555";
			mn = mn.substr(0,mn.find('\0'));
		}*/
		/*
		std::cout<<"\n k****"<< mn;
		std::cout<<"\n k****"<< mn.substr(0,mn.size()-1);
		if(mn.compare(mn.substr(0,mn.size()-1))==0){std::cout<<"\n equalizer";}
		mn = mn.c_str();
		std::cout<<"\n kkkkkk";
		std::cout<<"\n kkkkkk";
		x = std::stoi((mapy[mn])->getV());
		*/
		/*
		std::string mn = lines[v+1];
		
		if(mn[mn.size()]=='\0')
		{
			std::cout <<"\n\nsubstring getting fixed";
			mn = lines[v+1].substr(0,lines[v+1].size()-1);
		}
		std::cout<<"\n\nstring of the questionable location "<<lines[v+1];
		std::cout<<"\n\nstring mn"<<mn;
		if(mn.compare(lines[v+1])==0){ std::cout<<"\n here";}
		std::cout<<"\n\nstring of the questionable location "<<lines[v+1];
		x = std::stoi((mapy[mn])->getV());
		*/
		for(int z = 0; z < mn.size();z++){
			std::cout<<"\nhere: "<<z << "  ****"<<mn[z]<<"*****";
		}
		std::cout<<"\n 7777666kk"<<mn;
		std::cout<<"\n 7777666kk"<<mn;
		std::cout<<"\n kkkkk";
		if(mapy.find(mn)== mapy.end()){
			mn = mn.substr(0,mn.size()-1);
		}
	x = std::stoi((mapy[mn])->getV());
	}
	y += x;
	
	std::cout<<"\n\nvalue of y " << y;
	mapy[lines[1]]->setVal(std::to_string(y));
	cout<<"\n value of add:"<<mapy[lines[1]]->getV();

}

