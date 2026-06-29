#include <stdio.h>

// We need this library for Dynamic memory allocation functions
#include <stdlib.h>

int main(){
    // Write a program to allocate memory of size n, where n is entered by the user.
    
    int *ptr;
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // calloc initializes values with zero
    // Notice change in number of argumnents in calloc. malloc only takes one argument
    // ptr = (int*) calloc(n * sizeof(int));
       ptr = (int*) calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
    } else {
        printf("Memory allocated successfully\n");
    }

    
    for(int i=0; i<n; i++){
        printf("%d\n", ptr[i]);
    }
    
    free(ptr);
    printf("Memory released\n");

    return 0;
}
