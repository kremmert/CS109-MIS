#include "Sub.h"

Sub::Sub() {
}

Sub::Sub(const Sub& orig) {
}

Sub::~Sub() {
}
//Subtract the third parameter from the second parameter and store the result in the first parameter
void Sub::subtract(Var * a, int par1, int par2){
    int * b = a->getVal();
	*b = par1 - par2;
	

}
