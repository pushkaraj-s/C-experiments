#include <stdio.h>

//Sum of n natural numbers using recursion

int sum(int n);
int sumN = 0;

int main(){
    
    printf("Sum of numbers: %d \n", sum(5));
    return 0;
}

int sum(int n){
    
    if(n == 0){
        return sumN;
    }
    sumN = sumN + n;
    sum(n-1);
}
