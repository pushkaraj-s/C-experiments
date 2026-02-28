#include <stdio.h>
#include <math.h>

/*
This is a same code from Problem 5, only print statemetns are required to be changed.
*/

int main(){
    float x;
//Even if we get float value from user, we need to convert it to int before using '%'(mod).

    printf("Enter a number = ");
    scanf("%f", &x);

    //int integerPart = (int)x; //Making 'x' explicilty int data tyep

    if((int)x%2 == 0){  
        printf("Number is Even");
    }
    else{
        printf("Number is Odd");
    }

return 0;
}