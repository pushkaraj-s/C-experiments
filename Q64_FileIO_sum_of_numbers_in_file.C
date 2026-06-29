#include <stdio.h>

int main(){
    //2 numbers - a&b, are written in a file. Write a program to replace them eith their sum.
   
   FILE *fptr;
   fptr = fopen("test.txt", "r");

   if(fptr == NULL){
    printf("File does not exsist\n");
    return 0;
    }
   
    int a;
    fscanf(fptr, "%d", &a);
    printf("Number 1: %d\n", a);
    int b;
    fscanf(fptr, "%d", &b);
    printf("Number 2: %d\n", b);
   
    fclose(fptr);
    
    fptr = fopen("test.txt", "w");
    fprintf(fptr, "%d", a+b);

    printf("Sum stored in file\n");

    fclose(fptr);
    return 0;
}
