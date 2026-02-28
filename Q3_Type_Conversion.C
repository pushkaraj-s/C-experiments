#include <stdio.h>

//This question will explain us how type conversion works in C
//Relating to int -> float conversion and other examples.

int main(){

    //Determine if value should be 1 ot 2
    int a = 1.999999999;
    printf("Value of a = %d", a);
    
    return 0;
}

//Output shows C compiler never rounds off the value, it removes decimal completely