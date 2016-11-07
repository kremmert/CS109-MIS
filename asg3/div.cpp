#include "Div.h"
#include "common.h"

div::div() {
}

div::div(const div& orig) {
}

div::~div() {
}


//Divide the second parameter by the third parameter and store the result in the first parameter.	 
//Note: divide	by	zero	should	be	detected and reported.	

void div:: divide(int c, int a, int b){
    if(b == 0){
        std::cout<<"divide by zero error";
        return;
    }


}