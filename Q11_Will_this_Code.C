#include <stdio.h>


int main(){ 

    /* 
    
    Will this code :
    int x = 2 ;
    if( x = 1 ) {
    printf("x is equal to 1");
    } else {
    printf("x is not equal to 1");
    }
    a. give error
    b. print "x is equal to 1"
    c. print "x is not equal to 1"

    */

    Answer: In C,  0 is always treated as False.
            Any Non zero values like -1, -2, 1, 2 etc are treated as True

            In this code, on line 10, condition should be ( x == 1 );
            with current setup it will assign value of 1 into X,
            this will pass true for if condition.

            Hence we will get output as "X is equal to 1"


    return 0;
}