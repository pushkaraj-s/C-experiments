#include <stdio.h>

void doWork(int a, int b, int *sum, int *prod, int *avg);

int main(){
    
    //Write a program to calculate the sum, product and average of 2 numbers.
    //Print these values in main function;
   int a = 4;
   int b = 8;
   int sum, prod, avg = 0;
   
   doWork(a, b, &sum, &prod, &avg);
   printf("Sum = %d\nProduct = %d\nAverage = %d\n", sum, prod, avg);
    
    return 0;
}

void doWork(int a, int b, int *sum, int *prod, int *avg){
    *sum = a + b;
    *prod = a * b;
    *avg = (a+b)/2;
}
