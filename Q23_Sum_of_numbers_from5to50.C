#include <stdio.h>

//Calculate sum of all numbers from 5 to 50
//Including 5 and 50

int main(){

    int sum = 0;

    for(int i=5; i<=50; i++){
    sum = sum + i;

    }
    printf("Sum of Numbers: %d \n", sum);

    return 0;
}