#include <stdio.h>
#include <math.h>

//Use library funtions to calculate the square of number,
//Given by user

int main(){

    int n;
    printf("Enter a Number: ");
    scanf("%d", &n);

    int power = 0;
    power = pow(n,2); //Library funtion in math.h
              //Used to calculate power
    printf("Square is %d \n", power);


    return 0;
}