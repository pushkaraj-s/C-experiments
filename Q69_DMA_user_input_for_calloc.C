#include <stdio.h>
#include <stdlib.h>

int main(){
    // Create an array of size 5 (using calloc) & enter its values from the user.
    
    int *ptr;
    
    // Allocate memory for 5 intergers
    ptr = (int *) calloc(5, sizeof(int));

    //Check for allocation error
    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
    } else {
        printf("Memory allocated successfully\n");
    }
    
    for(int i=0; i<5; i++){
        printf("Enter integer %d: ", i);
        scanf("%d", &ptr[i]);
    }
    printf("\n");
    
    printf("Values stored in array \n");
    for(int i=0; i<5; i++){
        printf("%d\n", ptr[i]);
    }
    
    free(ptr);
    printf("Memory released\n");
    
    return 0;
}
