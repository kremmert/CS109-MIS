#include "sub.h"

Sub::Sub() {
}

Sub::Sub(const Sub& orig) {
}

Sub::~Sub() {
}
//Subtract the third parameter from the second parameter and store the result in the first parameter
Sub::subtract(int result, int par1, int par2){
    result.value = par1 - par2;
    return result;
}