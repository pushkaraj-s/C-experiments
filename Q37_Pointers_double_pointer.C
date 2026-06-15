#include <stdio.h>

int main(){
    
    //Print the value of 'i' from it's pointer to pointer (Double pointer)
    
    int i = 5;
    int *ptr = &i;
    int **pptr = &ptr;
    
    printf("Value of double pointer is: %d", **pptr);
    
    return 0;
}