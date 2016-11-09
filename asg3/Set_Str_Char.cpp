#include "Set_Str_Char.h"


Set_Str_Char::Set_Str_Char() {
}

Set_Str_Char::Set_Str_Char(const Set_Str_Char& orig) {
}

Set_Str_Char::~Set_Str_Char() {
	
}

Instructions * Set_Str_Char::clone(std::vector<std::string> lines){
	
}


void Set_Str_Char::functor(std::vector<std::string> lines,std::map <std::string,Instructions *> & mapy){
	
  /*  
    std::string a = lines[1];
	std::string b = lines[2];

	int x = 0;
	int y = 0;

		
	std::string mn = lines[2];
	if(mapy.find(mn)== mapy.end()){
		mn = mn.substr(0,mn.size()-1);
	}
	x = stoi(mapy[mn]->getV());

	mapy[lines[1]]->setVal(std::to_string(x));
*/
    std::string a = lines[2];
	std::string b = lines[3];
	int x = 0;
	std::string y;

	try{
		
		x = stoi(a);
		
	}
	catch(...)
	{
		std::string mn = lines[2];
		if(mapy.find(mn)== mapy.end()){
			mn = mn.substr(0,mn.size()-1);
		}

		x = std::stoi((mapy[mn])->getV());
	}


    std::string mn = lines[3];
    if(mapy.find(mn)== mapy.end()){
        mn = mn.substr(0,mn.size()-1);
    }
    if(mapy.find(mn)== mapy.end())
    {
        mn = mn.substr(0,mn.size()-1);
        if(mapy.find(mn)==mapy.end())
        {
            y = lines[3];
        }
        else
            y = mapy[mn]->getV();
    }
    else
        y = mapy[mn]->getV();


    std::string zz = lines[1];
    if(mapy.find(zz)== mapy.end()){
        zz = zz.substr(0,zz.size()-1);
    }
	
	std::string c = mapy[zz]->getV();
    c[x] = y[0];
	//mapy[lines[1]]->setVal(std::to_string(j));
	std::cout<<"\n result: "<<mapy[lines[1]]->getV();
	std::cout<<"\n";	
	
	
}