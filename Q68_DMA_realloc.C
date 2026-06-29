#include <stdio.h>
#include <stdlib.h>

int main(){
    // Allocate memory for 5 numbers. Then dynamically increase it to 8 numbers
    
    /***
    realloc() is used to reallocate(increase or decrease) memory using the same pointer & size
    Syntax: 
    ptr = realloc(ptr, newSize);
    ***/
    
    float *ptr;
    
    ptr = (float*) malloc(5 * sizeof(float));
    
    //Function returns NULL pointer if memory allocation has failed
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
    } else {
        printf("Memory allocated successfully\n");
    }

    for(int i=0; i<5; i++){
        printf("%f\n", ptr[i]);
    }
    printf("\n");
    
    //Reallocate to increase memory
    ptr = (float*) realloc(ptr, 8 * sizeof(float));
    
    if (ptr == NULL)
    {
        printf("Re-allocation failed\n");
    } else {
        printf("Re-allocation successful\n");
    }

    for(int i=0; i<8; i++){
        printf("%f\n", ptr[i]);
    }
    
    free(ptr);
    printf("Memory released\n");
    
    return 0;
}
