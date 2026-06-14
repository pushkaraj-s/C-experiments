#include <stdio.h>

//Factorial of a number using recursion

int factorial(int n);

int main(){

    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d: %d \n", n, factorial(n));

    return 0;
}

int factorial(int n){
    if(n == 0){
        return 1;
    }
    return n * factorial(n-1);
}
