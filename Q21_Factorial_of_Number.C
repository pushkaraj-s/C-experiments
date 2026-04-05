#include <stdio.h>

// Take input number from user and print factorial of that number.

int main(){

    int n = 0;
    double factorial = 1; //int will be very small for large numbers
    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i=1; i <= n; i++){
        factorial = factorial*i;

    }

    printf("Factorial is: %f \n", factorial);

    return 0;
}