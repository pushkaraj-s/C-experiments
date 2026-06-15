#include <stdio.h>

void swap(int a, int b);
void _swap(int *a, int *b);

int main(){
    
    //Swap 2 numbers a & b

    //For this example we will use "pass by reference"
    //Pass by reference will change original values at the memory location
    int a = 5;
    int b = 7;
    
    printf("Value before swap: a = %d , b = %d \n", a, b);
    _swap(&a, &b);
    printf("Value After swap: a = %d , b = %d \n", a, b);
    
    return 0;
}

//In case of Pass by Value this is how we can write a swap function.
    void swap(int a, int b){
        int temp = a;
        a = b;
        b = temp;
        printf("a = %d & b = %d \n", a,b);
    }

//Pass by reference
void _swap(int *a, int *b){
    
    int temp = *a;
    *a = *b;
    *b = temp;
}