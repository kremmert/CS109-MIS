#include "sub.h"

sub::sub() {
}

sub::sub(const sub& orig) {
}

sub::~sub() {
}
//Subtract the third parameter from the second parameter and store the result in the first parameter
sub::subtract(int result, int par1, int par2){
    result.value = par1 - par2;
    return result;
}