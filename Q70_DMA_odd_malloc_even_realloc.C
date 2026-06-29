#include <stdio.h>
#include <stdlib.h>

int main(){
    // Allocate memory to store first 5 odd numbers, then reallocate it to store first 6 even numbers
    
    int *ptr;
    ptr = (int *)calloc(5, sizeof(int));
    // Store prices in newly allocated memory
    ptr[0] = 1;
    ptr[1] = 3;
    ptr[2] = 5;
    ptr[3] = 7;
    ptr[4] = 9;

    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
    } else {
        printf("Memory allocated successfully\n");
    }
    
    for(int i=0; i<5; i++){
        printf("%d \n", ptr[i]);
    }
    
    printf("\n");
    printf("Reallocating Memory \n");
    
    //Reallocation
    ptr = (int *) realloc(ptr, 6 * sizeof(int));
    // Store prices in Re-allocated memory
    ptr[0] = 2;
    ptr[1] = 4;
    ptr[2] = 6;
    ptr[3] = 8;
    ptr[4] = 10;
    ptr[5] = 12;
    
    for(int i=0; i<5; i++){
        printf("%d \n", ptr[i]);
    }
    
    free(ptr);
    printf("Memory released\n");
    
    return 0;
}
