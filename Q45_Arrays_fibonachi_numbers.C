#include <stdio.h>

//Write a program to store the first n Fibonacci numbers in an array and print them.
// These are fibonacci numbers: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
// nth number = (n-1)th number + (n-2)th number

int main() {
    int n;
    printf("Enter n(n>2); ");
    scanf("%d", &n);

    int fib[n];
    fib[0] = 0;
    fib[1] = 1; //These 2 are always constant

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; // Calculate the next Fibonacci number
    }

    printf("The first %d Fibonacci numbers are: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }
    printf("\n");

    return 0;
}
