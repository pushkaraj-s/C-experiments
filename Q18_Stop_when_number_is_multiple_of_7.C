#include <stdio.h>

//Keep taking numbers as input from user until user
//enters a number which is multiple of 7

int main(){

    int n;
    

    while(n%7 != 0){
    printf("Enter a Number: ");
    scanf("%d", &n);

    }

    printf("Number is divisible by 7 \n");

    return 0;
}