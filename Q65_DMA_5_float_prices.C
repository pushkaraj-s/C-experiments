#include <stdio.h>

// We need this library for Dynamic memory allocation functions
#include <stdlib.h>

int main(){
    // Write a program to allocate memory to store 5 float prices
    
    float *ptr;
    
    // calloc initializes values with zero
    ptr = (float*) malloc(5 * sizeof(float));
    
    // Function returns NULL pointer if memory allocation has failed
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
    } else {
        printf("Memory allocated successfully\n");
    }

    // Store prices in newly allocated memory
    ptr[0] = 1;
    ptr[1] = 3;
    ptr[2] = 5;
    ptr[3] = 7;
    ptr[4] = 9;
    
    for(int i=0; i<5; i++){
        printf("%f\n", ptr[i]);
    }

    free(ptr);
    printf("Memory released\n");


    // Just as an experiment we can see what values are printed after releasing dynamic memory.
    for(int i=0; i<5; i++){
        printf("%f\n", ptr[i]);
    }
    // It will either print all zeros or some garbage values
    
    return 0;
}
