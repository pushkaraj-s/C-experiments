#include <stdio.h>

int main(){
    
    // Write a program to read 5 integers from a file
    
    FILE *fptr;
    fptr = fopen("test.txt", "r");
    int n;
    
    for(int i=0; i<5; i++){
        fscanf(fptr, "%d", &n);
        printf("Number = %d\n", n);
    }
    
    fclose(fptr); //Do not forget to close files after they are done using.
    
    return  0;
}

